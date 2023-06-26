#include "ModuleManager.h"

namespace ModuleManager {
	void init_modules() {
		/*COMBAT*/
		Module* auto_clicker = new AutoClicker("Auto Clicker", mdl::MODULE_CATEGORY::COMBAT);
		modules.insert(std::make_pair("Auto Clicker", auto_clicker));

		/*MOVEMENT*/

		/*PLAYER*/

		/*EXPLOIT*/

		/*VIUSAL*/
	}

	void unload_modules() {
		std::for_each(modules.begin(), modules.end(), [](const std::pair<const std::string, Module*>& pair) {
			delete pair.second;
		});
		modules.clear();
	}
}