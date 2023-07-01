#include "Setting.h"


Setting::Setting(const std::string name, const Module* parent, const stg::SETTING_TYPE type, const std::any default_value, const std::function<bool(void)> dependency) :
	SettingBase(name, parent, type, dependency), value(default_value) {
}

void Setting::sv(std::any value) {
	this->value = value;
}