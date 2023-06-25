#include "StringSetting.h"

StringSetting::StringSetting(const std::string name, const Module* parent, std::string default_value, const std::function<bool(void)> dependency) :
Setting(name, parent, stg::SETTING_TYPE::STRING, default_value, dependency) { }
