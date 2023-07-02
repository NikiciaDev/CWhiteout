#include "DrawableBool.h"

DrawableBool::DrawableBool(const sf::Vector2f position, BooleanSetting* setting, Whiteout& whiteout) : DrawableSetting(position, whiteout), setting(setting) { }

float DrawableBool::draw() {
	return 0;
}

bool DrawableBool::on_event(const Key key) {
	return false;
}