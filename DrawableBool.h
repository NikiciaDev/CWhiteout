#pragma once
#include "DrawableSetting.h"
#include "BooleanSetting.h"

class DrawableBool final : public DrawableSetting {
public:
	BooleanSetting* setting;

	DrawableBool(const sf::Vector2f position, const setting::Type type, BooleanSetting* setting, Whiteout& whiteout);

	void draw(float& height, sf::Vector2f outline_r_w) override;

	bool on_event(const Key key, const mdl::MODULE_CATEGORY current) override;
};