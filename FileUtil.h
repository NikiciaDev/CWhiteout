#pragma once
#include <string>
#include <fstream>
#include <Windows.h>
#include <Lmcons.h>
#include <filesystem>
#include "ConsoleUtil.h"

#pragma warning(disable: 4244) 

namespace ful {
	// If the operation succedes this function returns the path to the base enviorment.
	std::wstring create_envs();

	bool does_file_exist(std::string path_to_file);
}