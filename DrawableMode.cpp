#include "DrawableMode.h"

DrawableMode::DrawableMode(const sf::Vector2f position, const setting::Type type, ModeSetting* setting, Whiteout& whiteout) : DrawableSetting(position, type, whiteout), setting(setting) {}

void DrawableMode::draw(float& height, sf::Vector2f outline_r_w) { }

bool DrawableMode::on_event(const Key key) {
	return false;
}