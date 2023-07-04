#pragma once
#include "DrawableSetting.h"
#include "ColorSetting.h"

// https://stackoverflow.com/questions/48968250/sfml-color-picker-issue
// https://github.com/Dreamykass/bitsofkass/tree/master/cpp-sfml/2021-06-20--sfml-color-picker-lerp
class DrawableColor final : public DrawableSetting {
public:
	ColorSetting* setting;

	DrawableColor(const sf::Vector2f position, const setting::Type type, ColorSetting* setting, Whiteout& whiteout);

	void draw(float& height, sf::Vector2f outline_r_w) override;

	bool on_event(const Key key, const mdl::MODULE_CATEGORY current) override;

	void create_hue_vertecies(sf::VertexArray& vertices);
};