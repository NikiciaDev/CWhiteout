#pragma once
#define NOMINMAX

#include <Windows.h>
#include "Module.h"
#include "NumberSetting.h"
#include "BooleanSetting.h"
#include "Random.h"
#include "ConsoleUtil.h"
#include "Clock.h"

class AutoClicker final : public Module {
private:
	Random rndm;
	RandomVar<short> delay;

public:
	NumberSetting left_cps = NumberSetting("Left-Click CPS", this, 0, 25, 15, 1, num::Type::I, [] { return true; });
	NumberSetting random_left = NumberSetting("Left CPS Random", this, 0, 10, 2, 1, num::Type::I, [] { return true; });
	NumberSetting right_cps = NumberSetting("Right-Click CPS", this, 0, 25, 15, 1, num::Type::I, [] { return true; });
	NumberSetting random_right = NumberSetting("Right CPS Random", this, 0, 10, 2, 1, num::Type::I, [] { return true; });
	BooleanSetting change_rcd_delay = BooleanSetting("Change RCDT", this, false, [] { return true; });
	NumberSetting rcd_delay = NumberSetting("RCDT Delay", this, 0, 4, 4, 1, num::Type::I, [&] { return change_rcd_delay.gv<bool>(); });
	Clock<std::chrono::milliseconds> clock;

	AutoClicker(const std::string name, const mdl::MODULE_CATEGORY category);

	void on_call(std::map<const std::string, JavaClass*>& classes) override;
};