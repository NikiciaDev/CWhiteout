#include "LLInputUtil.h"

namespace liu {
    LRESULT CALLBACK keypress_handler(int nCode, WPARAM wParam, LPARAM lParam) {
        // Check if the event is a keypress event.
        if (nCode == HC_ACTION && wParam == WM_KEYDOWN) {
            PKBDLLHOOKSTRUCT hs = (PKBDLLHOOKSTRUCT) lParam;
            UINT64 c = MapVirtualKey(hs->vkCode, MAPVK_VK_TO_CHAR);
            if (c != 0) {
                std::for_each(ModuleManager::modules.begin(), ModuleManager::modules.end(), [c](const std::pair<const std::string, Module*>& pair) {
                    if (((char) c) == pair.second->keybind) pair.second->on_keypress(classes);
                });
            }
        }
        return 0;
    }
    LRESULT mousepress_handler(int nCode, WPARAM wParam, LPARAM lParam) {


        return 0;
    }
}