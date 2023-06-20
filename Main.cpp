#include <thread>
#include <cstdio>
#include <Windows.h>
#include <map>
#include <algorithm>
#include <jni.h>

#include "ClassLoader.h"
#include "JavaClass.h"

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
    clr::create_classes_from_ldrf("C:/Users/LRieh/source/repos/Whiteout/JClasses.ldrf", *classes);

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