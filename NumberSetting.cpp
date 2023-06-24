#include "NumberSetting.h"

NumberSetting::NumberSetting(const std::string name, const Module parent, const long double min_value, 
	const long double max_value, const long double default_value) : min_value(min_value), max_value(max_value), value(default_value),
	Setting(name, parent) {
	this->category = S_Category::NUMBER;
}