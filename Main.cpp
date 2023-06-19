#include <thread>
#include <cstdio>
#include <Windows.h>
#include <jni.h>

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
    init_variables();

    while (!GetAsyncKeyState(VK_DELETE)) {

    }

    FreeLibrary(instance);
}