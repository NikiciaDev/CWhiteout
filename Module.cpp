#include "Module.h"

Module::Module(const std::string name, const mdl::MODULE_CATEGORY category, const unsigned long long default_keybind) : name(name), category(category), keybind(default_keybind) {
	init_kb_string_represenation(default_keybind, keybind_s_rep);
}

void Module::on_call(std::map<const std::string, JavaClass*>& classes) { }

void Module::on_enable(std::map<const std::string, JavaClass*>& classes) { }

void Module::on_disable(std::map<const std::string, JavaClass*>& classes) { }

void Module::on_keypress(std::map<const std::string, JavaClass*>& classes) {
	if (is_active) {
		on_disable(classes);
	} else {
		on_enable(classes);
	}
	is_active = !is_active;
}

void Module::init_kb_string_represenation(unsigned long long keycode, std::string& string) {
	if (keycode == NULL) {
		string = "NULL";
	} else if (keycode == 65536) {
		string = "MB1";
	} else if (keycode == 131072) {
		string = "MB2";
	} else {
		string = (char) keycode;
	}
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
