#include "DrawableBool.h"

DrawableBool::DrawableBool(const sf::Vector2f position, const setting::Type type, BooleanSetting* setting, Whiteout& whiteout) : DrawableSetting(position, type, whiteout), setting(setting) { }

void DrawableBool::draw(float& height, sf::Vector2f outline_r_w) {
	if (!setting->dependency()) return;
	this->outline_r_w = outline_r_w;

	sf::Text sn = font::text(setting->name, pos);
	if (setting->gv<bool>()) render::rect(whiteout.window, sf::Vector2f(pos.x - 5, pos.y + 2.5f), sf::Vector2f(outline_r_w.x - 20, font::height()), Module::mdcc[setting->parent->category]);
	font::render(whiteout.window, sn);
	
	std::string render_v_s = setting->gv<bool>() ? "True" : "False";
	font::render(whiteout.window, render_v_s, sf::Vector2f(pos.x + outline_r_w.x - 20 - 10 - font::width(render_v_s), pos.y));
	height += font::height() + 5;
}

bool DrawableBool::on_event(const Key key, const mdl::MODULE_CATEGORY current) {
	if (bounds_contain(key, setting, current)) {
		if (key.keycode == 3) return true;
		setting->sv(!setting->gv<bool>());
		return true;
	}
	return false;
}