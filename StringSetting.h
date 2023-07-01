#pragma once
#include "Setting.h"

class StringSetting final : public Setting {
public:
	StringSetting(const std::string name, Module* parent, std::string default_value, const std::function<bool(void)> dependency);

	~StringSetting();
};