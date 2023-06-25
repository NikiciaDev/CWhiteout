#pragma once
#include <map>
#include <memory>
#include <string>
#include <algorithm>
#include "SettingBase.h"

namespace ModuleManager {
	std::map<const std::string, const Module*>* modules;

	void init_modules();
}