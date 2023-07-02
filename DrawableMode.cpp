#include "DrawableMode.h"

DrawableMode::DrawableMode(const sf::Vector2f position, ModeSetting* setting, Whiteout& whiteout) : DrawableSetting(position, whiteout), setting(setting) {}

float DrawableMode::draw() {
	return 0;
}

bool DrawableMode::on_event(const Key key) {
	return false;
}