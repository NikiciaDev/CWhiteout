#pragma once
#include "Setting.h"

class StringSetting final : public Setting<std::string> {
public:
	StringSetting(const std::string name, const Module* parent, std::string default_value, const std::function<bool(void)> dependency);
};