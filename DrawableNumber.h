#pragma once
#include "DrawableSetting.h"
#include "NumberSetting.h"
#include "MathUtil.h"
#include "LLInputUtil.h"

class DrawableNumber final : public DrawableSetting {
private:
	long double max, min, inc;

public:
	NumberSetting* setting;

	DrawableNumber(const sf::Vector2f position, const setting::Type type, NumberSetting* setting, Whiteout& whiteout);

	void draw(float& height, sf::Vector2f outline_r_w) override;

	bool on_event(const Key key, const mdl::MODULE_CATEGORY current) override;
};