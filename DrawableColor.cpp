#include "DrawableColor.h"

DrawableColor::DrawableColor(const sf::Vector2f position, const setting::Type type, ColorSetting* setting, Whiteout& whiteout) : DrawableSetting(position, type, whiteout), setting(setting) {}

void DrawableColor::draw(float& height, sf::Vector2f outline_r_w) { }

bool DrawableColor::on_event(const Key key) {
	return false;
}