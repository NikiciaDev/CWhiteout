#include "DrawableBool.h"

DrawableBool::DrawableBool(const sf::Vector2f position, const setting::Type type, BooleanSetting* setting, Whiteout& whiteout) : DrawableSetting(position, type, whiteout), setting(setting) { }

void DrawableBool::draw(float& height, sf::Vector2f outline_r_w) {
	//if (!setting->dependency()) return 0;
	if (!setting->gv<bool>()) render::rect(whiteout.window, sf::Vector2f(pos.x + 15, pos.y + height + 2.5f), sf::Vector2f(outline_r_w.x - 30, font::height()), Module::mdcc[setting->parent->category]);
}

bool DrawableBool::on_event(const Key key) {
	return false;
}