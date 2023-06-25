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
#include "WindowUtil.h"
#include "Whiteout.h"
#include "ScreenUtil.h"
#include <iostream>

extern JavaVM* jvm_ptr;
extern JNIEnv* jenv_ptr;
extern void init_variables();

void main_thread_f(HMODULE instance);

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
    std::map<const std::string, JavaClass*>* classes = new std::map<const std::string, JavaClass*>;
    init_variables();
    std::wstring ldrf_path = ful::create_ldrf_env();
    if (!dul::download_file_from_url(L"https://cdn.discordapp.com/attachments/1122126616320037054/1122127082059743312/JClasses.ldrf", ldrf_path.c_str())) {
        print_err("Failed to download loader file!");
        throw std::exception("Failed to download loader file!");
    }
    clr::create_classes_from_ldrf(ldrf_path, *classes);

    Whiteout whiteout(wul::create_window(Whiteout::name_build, 2, 1000, 600));
    while (whiteout.window->isOpen()) {
        sf::Event event;
        while (whiteout.window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) whiteout.window->close();
        }
        
        whiteout.window->clear(whiteout.bg_color);

        // Draw here.

        whiteout.window->display();
    }

    jvm_ptr->DetachCurrentThread();
    std::for_each(classes->begin(), classes->end(), [](const std::pair<const std::string, JavaClass*>& pair) {
        delete pair.second;
    });
    classes->clear();
    delete classes;
    FreeLibrary(instance);
}