#pragma once
#include <any>
#include <functional>
#include <string>

class Module;

namespace setting {
	enum Type;
}

class Setting {
protected:
	std::any value;

public:
	const std::string name;
	const Module* parent;
	const std::function<bool(void)> dependency;
	const setting::Type type;

	virtual ~Setting();

	Setting(const std::string name, const Module* parent, const std::any default_value, const setting::Type type, const std::function<bool(void)> dependency);

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