#pragma once
#include <any>
#include <functional>
#include <string>

class Module;

class Setting {
protected:
	std::any value;

public:
	const std::string name;
	const Module* parent;
	const std::function<bool(void)> dependency;

	virtual ~Setting();

	Setting(const std::string name, const Module* parent, const std::any default_value, const std::function<bool(void)> dependency);

	void sv(std::any value);

	template<class T>
	T gv() {
		return std::any_cast<T>(value);
	}
};