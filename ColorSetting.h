#pragma once
#include <SFML/Graphics.hpp>
#include "Setting.h"

class ColorSetting final : public Setting {
public:
	ColorSetting(const std::string name, const Module* parent, sf::Color default_value, const std::function<bool(void)> dependency);
};