#pragma once
#include "Setting.h"

class ModeSetting final : public Setting {
public:
	const std::vector<std::string> options;

	ModeSetting(const std::string name, Module* parent, unsigned short default_value, const std::vector<std::string> options, const std::function<bool(void)> dependency);

	~ModeSetting();
};