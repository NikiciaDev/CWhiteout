#include "ColorSetting.h"

ColorSetting::ColorSetting(const std::string name, const Module* parent, sf::Color default_value, const std::function<bool(void)> dependency) : 
	Setting(name, parent, default_value, setting::Type::COLOR, dependency) { }

ColorSetting::~ColorSetting() { }
