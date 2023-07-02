#pragma once
#include "DrawableSetting.h"
#include "StringSetting.h"

class DrawableString final : public DrawableSetting {
public:
	StringSetting* setting;

	DrawableString(const sf::Vector2f position, StringSetting* setting, Whiteout& whiteout);

	float draw() override;

	bool on_event(const Key key) override;
};