#include <thread>
#include <cstdio>
#include <Windows.h>
#include <map>
#include <algorithm>
#include <jni.h>

#include "ClassLoader.h"
#include "JavaClass.h"
#include "FileUtil.h"
#include "ConsoleUtil.h"
#include "DownloadUtil.h"

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
    while (!GetAsyncKeyState(VK_DELETE)) {
        //jenv_ptr->SetIntField(classes->find("Minecraft")->second->instance, *classes->find("Minecraft")->second->jfields.find("right_click_delay_timer")->second, 0);
    }
    
    jvm_ptr->DetachCurrentThread();

    std::for_each(classes->begin(), classes->end(), [](const std::pair<const std::string, JavaClass*>& pair) {
        delete pair.second;
    });
    classes->clear();
    delete classes;
    FreeLibrary(instance);
}