#pragma once
#include "Setting.h"

class NumberSetting : public Setting {
	long double min_value{ 0 }, max_value{ 0 };
	long double value{ 0 };

	NumberSetting(const std::string name, const Module parent, const long double min_value,
		const long double max_value, const long double default_value);
};