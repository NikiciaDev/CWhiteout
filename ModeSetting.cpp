#include "ModeSetting.h"

ModeSetting::ModeSetting(const std::vector<std::string> options, const std::string name, const Module* parent, std::string default_value,
	const std::function<bool(void)> dependency) : options(options), Setting(name, parent, default_value, dependency) { }

ModeSetting::~ModeSetting() { }
