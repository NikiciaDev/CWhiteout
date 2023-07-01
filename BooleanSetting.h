#pragma once
#include "Setting.h"

class BooleanSetting final : public Setting {
public:
	BooleanSetting(const std::string name, const Module* parent, bool default_value, const std::function<bool(void)> dependency);

	~BooleanSetting();
};