#include "Module.h"

Category::Category() { }

Category::Category(const Cat_E cat_e) : cat_e(cat_e) { }

Color Category::get_color(const Category category) {
	switch (category.cat_e) {
	default:
		return Color((unsigned char) 255, (unsigned char) 255, (unsigned char) 255);
		break;
	case Cat_E::COMBAT:
		return Color((unsigned char) 245, (unsigned char) 91, (unsigned char) 58);
		break;
	case Cat_E::MOVEMENT:
		return Color((unsigned char) 34, (unsigned char) 184, (unsigned char) 113);
		break;
	case Cat_E::PLAYER:
		return Color((unsigned char) 147, (unsigned char) 82, (unsigned char) 176);
		break;
	case Cat_E::EXPLOIT:
		return Color((unsigned char) 51, (unsigned char) 144, (unsigned char) 203);
		break;
	case Cat_E::VISUAL:
		return Color((unsigned char) 57, (unsigned char) 18, (unsigned char) 214);
		break;
	}
}

Module::Module(const std::string name, const Category category) : name(name), category(category) { }

void Module::init_settings(std::vector<Setting*>& settings) {
	this->settings = std::move(settings);
}

void Module::on_call() { 
	print_wrn("Base module on_call method called! This should not happen!");
}