#include "DrawableBool.h"

DrawableBool::DrawableBool(const sf::Vector2f position, BooleanSetting* setting) : DrawableSetting(position), setting(setting) { }

float DrawableBool::draw() {
	return 0;
}

bool DrawableBool::on_event(const Key key) {
	return false;
}