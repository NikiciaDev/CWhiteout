#include "SettingBase.h"


SettingBase::SettingBase(const std::string name, const Module* parent, const stg::SETTING_TYPE type, const std::function<bool(void)> dependency) :
	name(name), parent(parent), type(type), dependency(dependency) { }