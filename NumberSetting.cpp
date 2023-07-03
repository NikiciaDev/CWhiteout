#include "NumberSetting.h"

NumberSetting::NumberSetting(const std::string name, Module* parent, const std::any min, const std::any max, const std::any default_value, const std::any increment, const num::Type type, const std::function<bool(void)> dependency) :
	min(min), max(max), increment(increment), type(type), Setting(name, parent, default_value, setting::Type::NUMBER, dependency) { }

NumberSetting::~NumberSetting() { }

long double NumberSetting::force_any(const std::any any) {
	switch (type) {
	case num::Type::I:
		return std::any_cast<int>(any);
		break;
	case num::Type::LL:
		return std::any_cast<long long>(any);
		break;
	case num::Type::F:
		return std::any_cast<float>(any);
		break;
	case num::Type::D:
		return std::any_cast<double>(any);
		break;
	case num::Type::LD:
		return std::any_cast<long double>(any);
		break;
	}
	return 0;
}

void NumberSetting::force_set_any(std::any& any, const long double value) {
	switch (type) {
	case num::Type::I:
		any = (int) value;
		break;
	case num::Type::LL:
		any = (long long) value;
		break;
	case num::Type::F:
		any = (float) value;
		break;
	case num::Type::D:
		any = (double) value;
		break;
	case num::Type::LD:
		any = (long double) value;
		break;
	}
}