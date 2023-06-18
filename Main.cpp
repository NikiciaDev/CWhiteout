#include <thread>
#include <cstdio>

#include <Windows.h>
#include <jni.h>

void MainThread(HMODULE instance);

bool __stdcall DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved) {
    static FILE* file_ptr{ nullptr };
    static std::thread main_thread;

    if (reason == DLL_PROCESS_ATTACH) {
        AllocConsole();
        freopen_s(&file_ptr, "CONOUT$", "w", stdout);

        main_thread = std::thread([instance] { MainThread(instance); });

        if (main_thread.joinable()) main_thread.detach();
    } else if (reason == DLL_PROCESS_DETACH) {
        fclose(file_ptr);
        FreeConsole();
    }

    return true;
}

void MainThread(HMODULE instance) {
    JavaVM* jvm_ptr{ nullptr };
    jint result = JNI_GetCreatedJavaVMs(&jvm_ptr, 1, nullptr);

    void* env_ptr{ nullptr };
    jvm_ptr->AttachCurrentThread(&env_ptr, nullptr);

    while (!GetAsyncKeyState(VK_DELETE)) {

    }

    FreeLibrary(instance);
}