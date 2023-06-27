#pragma once
#include <map>
#include <string>
#include <algorithm>
#include "Module.h"
#include "AutoClicker.h"
#include "Timer.h"

namespace ModuleManager {
	extern std::map<const std::string, Module*> modules;

	// This function fills the modules map with one instance of each module!
	void init_modules();

	// Deletes the module pointers in the modules map.
	void unload_modules();

	std::string get_category_name_string(const mdl::MODULE_CATEGORY category);
};