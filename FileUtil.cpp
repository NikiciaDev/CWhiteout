#include "FileUtil.h"

std::wstring ful::create_ldrf_env() {
	DWORD size = UNLEN + 1;
	TCHAR username[UNLEN + 1];
	GetUserName((TCHAR*) username, &size);
	std::wstring ws_cu(&username[0]);
	std::string current_user(ws_cu.begin(), ws_cu.end());
	std::string base_path("C:\\Users\\");
	base_path += current_user;
	base_path += "\\AppData\\Roaming\\.whiteout";

	if (!std::filesystem::exists(base_path)) {
		if (!std::filesystem::create_directories(base_path)) {
			print_err("Failed to create .whiteout directory! Please create it manually inside your AppData\\Roaming folder!");
			throw std::exception("Failed to create .whiteout directory!");
		}
	}

	base_path += "\\JClasse.ldrf";
	return std::wstring(base_path.begin(), base_path.end());
}

bool ful::does_file_exist(std::string path_to_file) {
	std::fstream file(path_to_file);
	bool b = file.is_open();
	file.close();
	return b;
}