#pragma once
#include <string>
#include <vector>
#include <memory>
#include "ConsoleUtil.h"

class Setting; // Avoid circular dependency.

class Module {
public:
	const std::string name;
	std::vector<Setting*> settings;

	Module(const std::string name);

	virtual void on_call();
};