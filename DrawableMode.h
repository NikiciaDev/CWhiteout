#pragma once
#include "DrawableSetting.h"
#include "ModeSetting.h"

class DrawableMode final : public DrawableSetting {
public:
	ModeSetting* setting;

	DrawableMode(const sf::Vector2f position, ModeSetting* setting, Whiteout& whiteout);

	float draw() override;

	bool on_event(const Key key) override;
};