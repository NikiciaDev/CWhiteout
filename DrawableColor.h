#pragma once
#include "DrawableSetting.h"
#include "ColorSetting.h"
#include "LLInputUtil.h"

// https://stackoverflow.com/questions/48968250/sfml-color-picker-issue
// https://github.com/Dreamykass/bitsofkass/tree/master/cpp-sfml/2021-06-20--sfml-color-picker-lerp
class DrawableColor final : public DrawableSetting {
public:
	ColorSetting* setting;
	sf::RectangleShape color_rect;
	sf::RectangleShape bar_bounds;

	float hue_bar_x{ 0 };
	bool extened{ false };
	bool dragging_bar{ false }, dragging_rect{ false };

	DrawableColor(const sf::Vector2f position, const setting::Type type, ColorSetting* setting, Whiteout& whiteout);

	void draw(float& height, sf::Vector2f outline_r_w) override;

	bool on_event(const Key key, const mdl::MODULE_CATEGORY current) override;

	void create_hue_vertecies(sf::VertexArray& vertices, const sf::Vector2f pos, const float width_per, const float height);
};