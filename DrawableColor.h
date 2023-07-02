#pragma once
#include "DrawableSetting.h"
#include "ColorSetting.h"

class DrawableColor final : public DrawableSetting {
public:
	ColorSetting* setting;

	DrawableColor(const sf::Vector2f position, ColorSetting* setting, Whiteout& whiteout);

	float draw() override;

	bool on_event(const Key key) override;
};