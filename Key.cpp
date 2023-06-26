#include "Key.h"

Key::Key(const unsigned long keyode, const POINT mouse_pos) {
	this->keycode = keyode;
	this->mouse_pos = mouse_pos;
}

Key::Key() { }