#pragma once
#include <map>
#include <string>
#include <algorithm>
#include "Module.h"
#include "AutoClicker.h"

namespace ModuleManager {
	extern std::map<const std::string, Module*> modules;

	// This function fills the modules map with one instance of each module!
	void init_modules();

	// Deletes the module pointers in the modules map.
	void unload_modules();
};