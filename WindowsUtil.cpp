#include "WindowsUtil.h"

namespace wul {
	std::string get_foreground_window_title() {
		HWND h_foreground_window = GetForegroundWindow();
		int window_title_length = GetWindowTextLength(h_foreground_window);
		TCHAR* tc_window_title = new TCHAR[window_title_length + 1];
		GetWindowText(h_foreground_window, tc_window_title, window_title_length + 1);
		char* title = new char[window_title_length + 1];

		size_t st;
		wcstombs_s(&st, title, window_title_length + 1, tc_window_title, window_title_length + 1);
		std::string s(title);
		delete[] tc_window_title;
		delete[] title;

		return s;
	}

	std::string get_foreground_window_title_snap32() {
		HANDLE proc_snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		PROCESSENTRY32 pe32;
		pe32.dwSize = sizeof(PROCESSENTRY32);

		bool found_proc = Process32FirstW(proc_snap, &pe32);
		while (found_proc) {
			if (is_foreground_process(pe32.th32ProcessID)) {
				CloseHandle(proc_snap);
				std::wstring s(pe32.szExeFile);
				return std::string(s.begin(), s.end());
			}
			found_proc = Process32NextW(proc_snap, &pe32);
		}

		CloseHandle(proc_snap);
		return "";
	}

	bool is_foreground_process(DWORD pid) {
		HWND hwnd = GetForegroundWindow();
		if (hwnd == NULL) return false;

		DWORD gf_pid;
		if (GetWindowThreadProcessId(hwnd, &gf_pid) == 0) return false;

		return (gf_pid == pid);
	}
}