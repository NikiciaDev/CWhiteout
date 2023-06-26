#pragma once
#define NOMINMAX

#include <Windows.h>
#include <algorithm>
#include "ModuleManager.h"
#include "WindowsUtil.h"
#include "Key.h"

extern std::map<const std::string, JavaClass*> classes;
extern Whiteout* whiteout;

namespace liu {
    static std::vector<WPARAM> invalid_keys = {
        VK_ESCAPE, VK_TAB, VK_RETURN, VK_SPACE, VK_BACK,
        VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT, VK_DELETE,
        VK_INSERT, VK_HOME, VK_END, VK_PRIOR, VK_NEXT,
        VK_PAUSE, VK_SCROLL, VK_SNAPSHOT, VK_OEM_1, VK_OEM_2,
        VK_OEM_3, VK_OEM_4, VK_OEM_5, VK_OEM_6, VK_OEM_7,
        VK_OEM_8, VK_OEM_102, VK_F1, VK_F2, VK_F3,
        VK_F4, VK_F5, VK_F6, VK_F7, VK_F8, VK_F9,
        VK_F10, VK_F11, VK_F12
    };

    LRESULT CALLBACK keypress_handler(int nCode, WPARAM wParam, LPARAM lParam);

    LRESULT CALLBACK mousepress_handler(int nCode, WPARAM wParam, LPARAM lParam);
}
