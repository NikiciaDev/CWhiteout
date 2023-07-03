#pragma once
#include "DrawableSetting.h"
#include "ModeSetting.h"

class DrawableMode final : public DrawableSetting {
public:
	ModeSetting* setting;

	DrawableMode(const sf::Vector2f position, const setting::Type type, ModeSetting* setting, Whiteout& whiteout);

	void draw(float& height, sf::Vector2f outline_r_w) override;

	bool on_event(const Key key, const mdl::MODULE_CATEGORY current) override;
};