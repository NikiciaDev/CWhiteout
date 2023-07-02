#include "DrawableNumber.h"

DrawableNumber::DrawableNumber(const sf::Vector2f position, NumberSetting* setting, Whiteout& whiteout) : DrawableSetting(position, whiteout), setting(setting) {}

float DrawableNumber::draw() {
	return 0;
}

bool DrawableNumber::on_event(const Key key) {
	return false;
}