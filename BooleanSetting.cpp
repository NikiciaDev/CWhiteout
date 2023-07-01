#include "BooleanSetting.h"

BooleanSetting::BooleanSetting(const std::string name, const Module* parent, bool default_value, const std::function<bool(void)> dependency) :
	Setting(name, parent, default_value, setting::Type::BOOLEAN, dependency) {}

BooleanSetting::~BooleanSetting() { }