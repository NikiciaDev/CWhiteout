#include "LLInputUtil.h"

namespace liu {
    LRESULT CALLBACK keypress_handler(int nCode, WPARAM wParam, LPARAM lParam) {
        // Check if the event is a keypress event.
        if (nCode == HC_ACTION && wParam == WM_KEYDOWN) {
            PKBDLLHOOKSTRUCT hs = (PKBDLLHOOKSTRUCT) lParam;
            unsigned long long c = MapVirtualKey(hs->vkCode, MAPVK_VK_TO_CHAR);
            if (c != 0) {
                whiteout->dispatch_keypress(c, !jenv_ptr->CallStaticBooleanMethod(classes.find("Display")->second->jclass, *classes.find("Display")->second->jmethods.find("is_active")->second));
            }
        }
        return 0;
    }

    // hs->mouseData = 65536 == XBUTTON1 | hs->mouseData = 131072 == XBUTTON2
    LRESULT mousepress_handler(int nCode, WPARAM wParam, LPARAM lParam) {
        if (nCode == HC_ACTION && wParam == WM_XBUTTONDOWN) {
            PMSLLHOOKSTRUCT hs = (PMSLLHOOKSTRUCT) lParam;
            if ((hs->mouseData == 65536 || hs->mouseData == 131072)) {
                whiteout->dispatch_keypress(hs->mouseData, !jenv_ptr->CallStaticBooleanMethod(classes.find("Display")->second->jclass, *classes.find("Display")->second->jmethods.find("is_active")->second));
            }
        }
        return 0;
    }
}