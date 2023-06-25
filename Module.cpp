#include "Module.h"

Module::Module(const std::string name, const MODULE_CATEGORY category) : name(name), category(category) { }

void Module::on_call() {
	print_wrn("Base module on_call called. This should not happen!");
}

sf::Color Module::get_module_color(const Module& module) {
	switch (module.category) {
	default:
		print_wrn("Module category undeclared!");
		return sf::Color::White;
		break;
	case mdl::MODULE_CATEGORY::COMBAT:
		return sf::Color(245, 91, 58);
		break;
	case mdl::MODULE_CATEGORY::MOVEMENT:
		return sf::Color(34, 184, 113);
		break;
	case mdl::MODULE_CATEGORY::PLAYER:
		return sf::Color(147, 82, 176);
		break;
	case mdl::MODULE_CATEGORY::VISUAL:
		return sf::Color(57, 18, 214);
		break;
	case mdl::MODULE_CATEGORY::EXPLOIT:
		return sf::Color(51, 144, 203);
		break;
	}
}