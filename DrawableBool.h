#pragma once
#include "DrawableSetting.h"
#include "BooleanSetting.h"

class DrawableBool final : public DrawableSetting {
public:
	BooleanSetting* setting;

	DrawableBool(const sf::Vector2f position, BooleanSetting* setting);

	float draw() override;

	bool on_event(const Key key) override;
};