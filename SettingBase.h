#pragma once
#include <string>
#include <functional>
#include "Module.h"

namespace stg {
	enum SETTING_TYPE;
}

class SettingBase {
public:
	const std::string name;
	const stg::SETTING_TYPE type;
	const Module* parent;
	const std::function<bool(void)> dependency;

	SettingBase(const std::string name, const Module* parent, const stg::SETTING_TYPE type, const std::function<bool(void)> dependency);
};

namespace stg {
	enum SETTING_TYPE {
		UNDECLARED,
		NUMBER,
		MODE,
		BOOLEAN,
		STRING,
		COLOR
	};
}