#pragma once
#include "DrawableSetting.h"
#include "ColorSetting.h"
#include "LLInputUtil.h"

// https://stackoverflow.com/questions/48968250/sfml-color-picker-issue
// https://github.com/Dreamykass/bitsofkass/tree/master/cpp-sfml/2021-06-20--sfml-color-picker-lerp
class DrawableColor final : public DrawableSetting {
public:
	sf::Color base_rgb, base_rgb_sat;
	ColorSetting* setting;
	sf::RectangleShape color_rect;
	sf::RectangleShape bar_bounds, sat_bounds, val_bounds;

	float hue_bar_x{ 300 }, sat_bar_x{ 300 }, val_bar_x{ 300 };
	bool dragging_bar{ false }, dragging_s{ false }, dragging_v{ false };
	bool extened{ false };

	DrawableColor(const sf::Vector2f position, const setting::Type type, ColorSetting* setting, Whiteout& whiteout);

	void draw(float& height, sf::Vector2f outline_r_w) override;

	bool on_event(const Key key, const mdl::MODULE_CATEGORY current) override;

	void create_hue_vertecies(sf::VertexArray& vertices, const sf::Vector2f pos, const float width_per, const float height);

	void add_quad_verts(sf::VertexArray& vertices, const sf::Vector2f pos, const sf::Vector2f size, const sf::Color base_color, const sf::Color end_color);

	void manage_drag(const sf::FloatRect& global_bounds, const sf::Vector2f _pos, bool& drag_bool, float& bar_x, const float y, const float rec_w);
};