#pragma once
#include "Setting.h"

class ModeSetting final : public Setting {
public:
	const std::vector<std::string> options;

	ModeSetting(const std::vector<std::string> options, const std::string name, const Module* parent, std::string default_value, const std::function<bool(void)> dependency);

	~ModeSetting();
};