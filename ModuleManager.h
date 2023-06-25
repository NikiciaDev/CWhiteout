#pragma once
#include <map>
#include <string>
#include <memory>
#include "Module.h"

namespace ModuleManager {
	static std::map<const std::string, const std::unique_ptr<Module>> modules;

	// This function fills the modules map with one instance of each module!
	void init_modules();
}