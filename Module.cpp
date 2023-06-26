#include "Module.h"
#include "NumberSetting.h"

Module::Module(const std::string name, const mdl::MODULE_CATEGORY category) : name(name), category(category) { }

void Module::on_call(std::map<const std::string, JavaClass*>& classes) {
	
}

void Module::on_draw(const Whiteout& whiteout) {
	
}

void Module::on_enable(std::map<const std::string, JavaClass*>&) {
	
}

void Module::on_disable(std::map<const std::string, JavaClass*>&) {
	
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