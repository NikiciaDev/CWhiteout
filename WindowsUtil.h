#pragma once
#include <Windows.h>
#include <tlhelp32.h>
#include <string>

namespace wul {
	std::string get_foreground_window_title();

	std::string get_foreground_window_title_snap32();

	bool is_foreground_process(DWORD pid);
}