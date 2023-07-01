#pragma once
#include <any>
#include "SettingBase.h"

class Setting : public SettingBase {
protected:
	std::any value;

public:
	Setting(const std::string name, const Module* parent, const stg::SETTING_TYPE type, const std::any default_value, const std::function<bool(void)> dependency);

	void sv(std::any value);

	template<class T>
	T gv() {
		return std::any_cast<T>(value);
	}
};