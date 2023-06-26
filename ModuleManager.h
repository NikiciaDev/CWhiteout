#pragma once
#include <map>
#include <string>
#include <algorithm>
#include "Module.h"
#include "AutoClicker.h"
#include <iostream>

namespace ModuleManager {
	extern std::map<const std::string, const std::unique_ptr<Module>> modules;

	// This function fills the modules map with one instance of each module!
	void init_modules();
};