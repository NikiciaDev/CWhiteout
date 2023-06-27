#include "ModuleManager.h"

namespace ModuleManager {
	void init_modules() {
		/*COMBAT*/
		Module* auto_clicker = new AutoClicker("Auto Clicker", mdl::MODULE_CATEGORY::COMBAT);
		modules.insert(std::make_pair("Auto Clicker", auto_clicker));

		/*MOVEMENT*/

		/*PLAYER*/

		/*EXPLOIT*/
		Module* timer = new Timer("Timer", mdl::MODULE_CATEGORY::EXPLOIT);
		modules.insert(std::make_pair("Timer", timer));

		/*VIUSAL*/
	}

	void unload_modules() {
		std::for_each(modules.begin(), modules.end(), [](const std::pair<const std::string, Module*>& pair) {
			delete pair.second;
		});
		modules.clear();
	}
	std::string get_category_name_string(const mdl::MODULE_CATEGORY category) {
		switch (category) {
		default:
			return std::string("UNDEFINED");
			break;
		case mdl::MODULE_CATEGORY::COMBAT:
			return std::string("COMBAT");
			break;
		case mdl::MODULE_CATEGORY::MOVEMENT:
			return std::string("MOVEMENT");
			break;
		case mdl::MODULE_CATEGORY::PLAYER:
			return std::string("PLAYER");
			break;
		case mdl::MODULE_CATEGORY::VISUAL:
			return std::string("VISUAL");
			break;
		case mdl::MODULE_CATEGORY::EXPLOIT:
			return std::string("EXPLOIT");
			break;
		}
	}
}