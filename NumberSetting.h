#pragma once
#include <any>
#include "Setting.h"

class NumberSetting final : public Setting<std::any> {
public:
	const std::any min, max;
	const std::any increment;

	NumberSetting(const std::string name, const Module* parent, const std::any min, const std::any max, const std::any default_value, const std::any increment, const std::function<bool(void)> dependency);

	template<class T>
	T vl() {
		return std::any_cast<T>(value);
	}

	template<class T>
	T mn() {
		return std::any_cast<T>(min);
	}

	template<class T>
	T mx() {
		return std::any_cast<T>(max);
	}

	template<class T>
	T Nic() {
		return std::any_cast<T>(increment);
	}
};