#pragma once
#include <SFML/Graphics.hpp>
#include "Setting.h"

class ColorSetting final : public Setting {
public:
	ColorSetting(const std::string name, Module* parent, const sf::Color default_value, const std::function<bool(void)> dependency);

	~ColorSetting();
};