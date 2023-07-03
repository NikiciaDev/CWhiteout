#pragma once
#include <any>
#include <functional>
#include <string>
#include "Module.h"

namespace setting {
	enum Type;
}

class Setting {
public:
	std::any value;
	const std::string name;
	const std::function<bool(void)> dependency;
	const setting::Type type;
	Module* parent;

	virtual ~Setting();

	Setting(const std::string name, Module* parent, const std::any default_value, const setting::Type type, const std::function<bool(void)> dependency);

	void sv(std::any value);
	 
	template<class T>
	T gv() {
		return std::any_cast<T>(value);
	}
};

namespace setting {
	enum Type {
		BOOLEAN,
		COLOR,
		MODE,
		NUMBER,
		STRING
	};
}