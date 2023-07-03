#pragma once
#include <any>
#include "Setting.h"

namespace num {
	enum Type;
}

class NumberSetting final : public Setting {
public:
	const num::Type type;
	const std::any min, max;
	const std::any increment;

	NumberSetting(const std::string name, Module* parent, const std::any min, const std::any max, const std::any default_value, const std::any increment, const num::Type type, const std::function<bool(void)> dependency);

	~NumberSetting();

	// DO NOT USE UNLESS YOU ABSOLUTLEY HAVE TO!
	long double force_any(const std::any any);

	// DO NOT USE UNLESS ABSOLUTLEY NECESSARY!
	void force_set_any(std::any& any, const long double value);

	template<class T>
	T mn() {
		return std::any_cast<T>(min);
	}

	template<class T>
	T mx() {
		return std::any_cast<T>(max);
	}

	template<class T>
	T inc() {
		return std::any_cast<T>(increment);
	}
};

namespace num {
	enum Type {
		I,
		LL,
		F,
		D,
		LD
	};
}