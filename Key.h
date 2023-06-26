#pragma once
#include <Windows.h>

class Key final {
public:
	unsigned long keycode { 0 };
	POINT mouse_pos{ 0, 0 };

	Key();

	explicit Key(const unsigned long keyode, const POINT mouse_pos);
};