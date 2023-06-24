#pragma once
#include "Module.h"
#include "NumberSetting.h"

class AutoClicker : public Module {
public:
	NumberSetting right_cps(), left_cps();
	NumberSetting place_delay();

	AutoClicker(const std::string name, const Category category);

	void on_call() override;
};