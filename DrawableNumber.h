#pragma once
#include "DrawableSetting.h"
#include "NumberSetting.h"

class DrawableNumber final : public DrawableSetting {
public:
	NumberSetting* setting;

	DrawableNumber(const sf::Vector2f position, const setting::Type type, NumberSetting* setting, Whiteout& whiteout);

	void draw(float& height, sf::Vector2f outline_r_w) override;

	bool on_event(const Key key) override;
};