#pragma once
#include "DrawableSetting.h"
#include "ColorSetting.h"

class DrawableColor final : public DrawableSetting {
public:
	ColorSetting* setting;

	DrawableColor(const sf::Vector2f position, const setting::Type type, ColorSetting* setting, Whiteout& whiteout);

	void draw(float& height, sf::Vector2f outline_r_w) override;

	bool on_event(const Key key) override;
};