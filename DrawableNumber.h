#pragma once
#include "DrawableSetting.h"
#include "NumberSetting.h"

class DrawableNumber final : public DrawableSetting {
public:
	NumberSetting* setting;

	DrawableNumber(const sf::Vector2f position, NumberSetting* setting, Whiteout& whiteout);

	float draw() override;

	bool on_event(const Key key) override;
};