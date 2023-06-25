#pragma once
#include "Setting.h"

template<class T>
class NumberSetting final : public Setting<T> {
public:
	const T min, max;

	/*****************************************************IMPLEMENTATION*****************************************************/
	// This has to be done this way because of the way C++ handels template classes.

	inline NumberSetting(const std::string name, const Module* parent, const T min, const T max, const T default_value, const std::function<bool(void)> dependency) :
		min(min), max(max), Setting<T>(name, parent, stg::SETTING_TYPE::NUMBER, default_value, dependency) {}
};