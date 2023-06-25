#pragma once
#include "SettingBase.h"

template<class T>
class Setting : public SettingBase {
public:
	T value;

	/*****************************************************IMPLEMENTATION*****************************************************/
	// This has to be done this way because of the way C++ handels template classes.

	inline Setting(const std::string name, const Module* parent, const stg::SETTING_TYPE type, T default_value, const std::function<bool(void)> dependency) :
		SettingBase(name, parent, type, dependency), value(default_value) {
	}
};