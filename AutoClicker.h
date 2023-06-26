#pragma once
#define NOMINMAX

#include <Windows.h>
#include "Module.h"
#include "NumberSetting.h"
#include "BooleanSetting.h"
#include "RandomUtil.h"
#include "ConsoleUtil.h"
#include "Clock.h"

class AutoClicker final : public Module {
public:
	const NumberSetting<short> left_cps = NumberSetting<short>("Left-Click CPS", this, 0, 20, 10, 1, [] { return true; });
	const NumberSetting<short> right_cps = NumberSetting<short>("Right-Click CPS", this, 0, 20, 10, 1, [] { return true; });
	const NumberSetting<short> random_left = NumberSetting<short>("Left CPS Random", this, 0, 10, 2, 1, [] { return true; });
	const NumberSetting<short> random_right = NumberSetting<short>("Right CPS Random", this, 0, 10, 2, 1, [] { return true; });
	const BooleanSetting change_rcd_delay = BooleanSetting("Change RCD Ddelay", this, false, [] { return true; });
	const NumberSetting<short> rcd_delay = NumberSetting<short>("RCD Delay", this, 0, 4, 4, 1, [&] { return change_rcd_delay.value; });
	Clock<std::chrono::milliseconds> clock;

	AutoClicker(const std::string name, const mdl::MODULE_CATEGORY category);

	void on_call(std::map<const std::string, JavaClass*>* classes) override;
};