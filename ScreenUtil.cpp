#include "ScreenUtil.h"
#include <iostream>

const sf::Vector2<const unsigned int> get_screen_dimensions() {
	return sf::Vector2<const unsigned int>(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
}