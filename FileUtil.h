#pragma once
#include <string>
#include <fstream>
#include <Windows.h>
#include <Lmcons.h>
#include <filesystem>
#include "ConsoleUtil.h"

#pragma warning(disable: 4244) 

namespace ful {
	// If the operation succedes this function returns the path to the ldrf.
	std::wstring create_ldrf_env();

	bool does_file_exist(std::string path_to_file);
}