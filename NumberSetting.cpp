#include "NumberSetting.h"

NumberSetting::NumberSetting(const std::string name, const Module* parent, const std::any min, const std::any max, const std::any default_value, const std::any increment, const std::function<bool(void)> dependency) :
	min(min), max(max), increment(increment), Setting(name, parent, default_value, dependency) { }

NumberSetting::~NumberSetting() { }