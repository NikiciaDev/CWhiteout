#include "DrawableSetting.h"

DrawableSetting::DrawableSetting(const sf::Vector2f pos, const setting::Type type, Whiteout& whiteout) : pos(pos), type(type), whiteout(whiteout) {}

bool DrawableSetting::bounds_contain(const Key key, const Setting* setting, const mdl::MODULE_CATEGORY current) {
	if (!setting->dependency() || setting->parent->category != current) return false;
	if (sf::FloatRect(pos.x - 5, pos.y + 2.5f, outline_r_w.x - 20, font::height()).contains(sf::Vector2f(key.mouse_pos.x, key.mouse_pos.y))) {
		return true;
	}
	return false;
}

DrawableSetting::~DrawableSetting() {}

void DrawableSetting::draw(float& height, sf::Vector2f outline_r_w) { }

bool DrawableSetting::on_event(const Key key, const mdl::MODULE_CATEGORY current) { return false; }