#pragma once
#include <map>
#include <string>
#include <algorithm>
#include "Module.h"
#include "AutoClicker.h"
#include "Timer.h"
#include "WGUI.h"

namespace ModuleManager {
	extern std::map<const std::string, Module*> modules;
	extern std::vector<Module*> c_modules;
	extern std::vector<Module*> m_modules;
	extern std::vector<Module*> p_modules;
	extern std::vector<Module*> v_modules;
	extern std::vector<Module*> e_modules;

	// This function fills the modules map with one instance of each module!
	void init_modules();

	// This function get called in init_modues. Do not call anywhere else!
	void fill_vectors();

	// Deletes the module pointers in the modules map.
	void unload_modules();

	std::vector<Module*> module_vec_by_cat(mdl::MODULE_CATEGORY category);

	std::string get_category_name_string(const mdl::MODULE_CATEGORY category);
};