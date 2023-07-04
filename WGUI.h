#pragma once
#include "Module.h"
#include "ColorSetting.h"
#include "BooleanSetting.h"

class WGUI final : public Module {
public:
	ColorSetting base_color = ColorSetting("Color", this, Whiteout::base_color, [] { return true; });
	BooleanSetting category_colors = BooleanSetting("Category Colors", this, true, [] { return true; });

	WGUI(const std::string name, const mdl::MODULE_CATEGORY category);

	void on_call(std::map<const std::string, JavaClass*>& classes) override;
};