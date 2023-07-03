#include "LLInputUtil.h"

namespace liu {
    LRESULT CALLBACK keypress_handler(int nCode, WPARAM wParam, LPARAM lParam) {
        // Check if the event is a keypress event.
        if (nCode == HC_ACTION && wParam == WM_KEYDOWN) {
            const bool ext = !jenv_ptr->CallStaticBooleanMethod(classes.find("Display")->second->jclass, *classes.find("Display")->second->jmethods.find("is_active")->second);
            if (!ext || whiteout->window.hasFocus()) {
                PKBDLLHOOKSTRUCT hs = (PKBDLLHOOKSTRUCT) lParam;
                unsigned long long c = MapVirtualKey(hs->vkCode, MAPVK_VK_TO_CHAR);
                if (c != 0) {
                    POINT p{ 0, 0 };
                    whiteout->dispatch_keypress(Key(c, p), ext);
                }
            }
        }
        return 0;
    }

    // hs->mouseData = 65536 == XBUTTON1 | hs->mouseData = 131072 == XBUTTON2.
    // XBUTTON2 is weirdly bugged sometimes.
    LRESULT mousepress_handler(int nCode, WPARAM wParam, LPARAM lParam) {
        if (nCode == HC_ACTION && (wParam == WM_XBUTTONDOWN || wParam == WM_LBUTTONDOWN || wParam == WM_RBUTTONDOWN || wParam == WM_LBUTTONUP || wParam == WM_MOUSEWHEEL) ) {
            const bool ext = !jenv_ptr->CallStaticBooleanMethod(classes.find("Display")->second->jclass, *classes.find("Display")->second->jmethods.find("is_active")->second);
            if (!ext || whiteout->window.hasFocus()) {
                PMSLLHOOKSTRUCT hs = (PMSLLHOOKSTRUCT) lParam;
                if (wParam == WM_LBUTTONDOWN) hs->mouseData = 1;
                if (wParam == WM_RBUTTONDOWN) hs->mouseData = 2;
                if (wParam == WM_LBUTTONUP) hs->mouseData = 3;
                if (hs->mouseData == 4287102976) hs->mouseData = 4;
                if (hs->mouseData == 7864320) hs->mouseData = 5;
                POINT p{ 0, 0 };
                GetCursorPos(&p);
                ScreenToClient(whiteout->window.getSystemHandle(), &p);
                whiteout->dispatch_keypress(Key(hs->mouseData, p), ext);
            }
        }
        return 0;
    }

    sf::Vector2i get_cursor_pos() {
        POINT p{ 0, 0 };
        GetCursorPos(&p);
        ScreenToClient(whiteout->window.getSystemHandle(), &p);
        return sf::Vector2i(p.x, p.y);
    }
}