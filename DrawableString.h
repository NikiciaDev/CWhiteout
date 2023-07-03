#pragma once
#include "DrawableSetting.h"
#include "StringSetting.h"

class DrawableString final : public DrawableSetting {
public:
	StringSetting* setting;

	DrawableString(const sf::Vector2f position, const setting::Type type, StringSetting* setting, Whiteout& whiteout);

	void draw(float& height, sf::Vector2f outline_r_w) override;

	bool on_event(const Key key, const mdl::MODULE_CATEGORY current) override;
};