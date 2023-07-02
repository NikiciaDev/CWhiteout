#define NOMINMAX

#include <thread>
#include <cstdio>
#include <Windows.h>
#include <map>
#include <algorithm>
#include <jni.h>
#include <SFML/Graphics.hpp>

#include "ClassLoader.h"
#include "JavaClass.h"
#include "FileUtil.h"
#include "ConsoleUtil.h"
#include "DownloadUtil.h"
#include "Whiteout.h"
#include "ModuleManager.h"
#include "LLInputUtil.h"
#include "FontRenderer.h"
#include "GUI.h"
#include "CommandManager.h"

extern Whiteout* whiteout;
extern JavaVM* jvm_ptr;
extern JNIEnv* jenv_ptr;
extern void init_variables(const std::string font_path);

void main_thread_f(HMODULE instance);

std::map<const std::string, JavaClass*> classes;

bool __stdcall DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved) {
    static FILE* file_ptr{ nullptr };
    static std::thread main_thread;

    if (reason == DLL_PROCESS_ATTACH) {
        AllocConsole();
        freopen_s(&file_ptr, "CONOUT$", "w", stdout);

        main_thread = std::thread([instance] { main_thread_f(instance); });

        if (main_thread.joinable()) main_thread.detach();
    } else if (reason == DLL_PROCESS_DETACH) {
        fclose(file_ptr);
        FreeConsole();
    }

    return true;
}

void main_thread_f(HMODULE instance) {
    std::wstring base_env_path = ful::create_envs();
    std::wstring ldrf_path(base_env_path); ldrf_path += L"\\JClasses.ldrf";
    std::wstring font_path(base_env_path); font_path += L"\\font";
    if (!dul::download_file_from_url(L"https://cdn.discordapp.com/attachments/1122126616320037054/1122928370850746458/JClasses.ldrf", ldrf_path.c_str())) {
        print_err("Failed to download loader file!");
        throw std::exception("Failed to download loader file!");
    }
    dul::download_fonts(font_path.c_str());
    init_variables(std::string(font_path.begin(), font_path.end()));
    clr::create_classes_from_ldrf(ldrf_path, classes);

    HHOOK k_h_hook = SetWindowsHookEx(WH_KEYBOARD_LL, liu::keypress_handler, NULL, 0);
    HHOOK m_h_hook = SetWindowsHookEx(WH_MOUSE_LL, liu::mousepress_handler, NULL, 0);
    ModuleManager::init_modules(); // Dont call fill_vectors!
    CommandManager::init_commands();
    GUI gui(whiteout);

    std::atomic<bool> should_exit{ false };
    std::atomic<bool> has_finnished { false };

    whiteout->window.setActive(false); // This disables drawing in the current thread!
    std::thread draw_thread([&gui, &should_exit, &has_finnished]() {
        whiteout->window.setActive();
        while (!should_exit) {
            Key key;
            while (whiteout->poll_keypresses(key, true)) {
                gui.on_key_event(key);
            }

            whiteout->window.clear(whiteout->bg_color);

            gui.draw_modules();
            gui.draw_base(); // This has to draw last.
            whiteout->window.display();
        }
        has_finnished = true;
    });
    draw_thread.detach();

    std::string s_exit;
    while (whiteout->window.isOpen()) {
        sf::Event event;
        while (whiteout->window.pollEvent(event)) {
            switch (event.type) {
            default:
                break;
            case sf::Event::Closed:
                should_exit = true;
                s_exit = SentCommand::get_pre_string(*whiteout);
                gui.terminal.sent_commands.push_back(SentCommand(gui.terminal.input_pos, s_exit + "UNINJECT", "Trying to uninject. Please wait and do not forcefully exit."));
                while (true) {
                    if (has_finnished) {
                        gui.terminal.clean();
                        gui.csb.current = mdl::MODULE_CATEGORY::UNDECLARED;
                        whiteout->window.close();
                        break;
                    }
                }
                break;
            case sf::Event::Resized: // This prevents sprites from scaling with the window. We need this to keep the outline and make scrolling possibile.
                whiteout->view = sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height));
                whiteout->window.setView(whiteout->view);
                break;
            }
        }

        Key key;
        while (whiteout->poll_keypresses(key, false)) {
            std::for_each(ModuleManager::modules.begin(), ModuleManager::modules.end(), [key](const std::pair<const std::string, Module*>& pair) {
                if (pair.second->keybind == key.keycode) pair.second->on_keypress(classes);
            });
        }

        std::for_each(ModuleManager::modules.begin(), ModuleManager::modules.end(), [](const std::pair<const std::string, Module*>& pair) {
            if (pair.second->is_active) pair.second->on_call(classes);
        });
    }
    
    jvm_ptr->DetachCurrentThread();
    std::for_each(classes.begin(), classes.end(), [](const std::pair<const std::string, JavaClass*>& pair) {
        delete pair.second;
    });

    classes.clear();
    UnhookWindowsHookEx(k_h_hook);
    UnhookWindowsHookEx(m_h_hook);
    ModuleManager::unload_modules();
    CommandManager::unload_commands();
    FreeLibrary(instance);
}