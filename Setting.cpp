#include "Setting.h"

Setting::Setting(const std::string name, const Module* parent, std::any default_value, const std::function<bool(void)> dependency) :
	name(name), parent(parent), dependency(dependency), value(default_value) { }