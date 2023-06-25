#pragma once
#include <string>
#include <memory>
#include "Module.h"

enum SETTING_TYPE;

class Setting {
public:
	const std::string name;
	const SETTING_TYPE type;
	const std::shared_ptr<Module> parent;

	Setting(const std::string name, const std::shared_ptr<Module> parent, const SETTING_TYPE type);
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