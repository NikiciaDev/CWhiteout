#include "ModeSetting.h"

ModeSetting::ModeSetting(const std::string name, Module* parent, unsigned short default_value, const std::vector<std::string> options,
	const std::function<bool(void)> dependency) : options(options), Setting(name, parent, default_value, setting::Type::MODE, dependency) { }

ModeSetting::~ModeSetting() { }