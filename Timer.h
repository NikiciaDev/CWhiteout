#pragma once
#include "Module.h"
#include "NumberSetting.h"
#include "BooleanSetting.h"

class Timer final : public Module {
public:
	NumberSetting speed = NumberSetting("Timer Speed", this, 0.1f, 10, 2, 0.025, [] { return true; });
	BooleanSetting tick = BooleanSetting("Tick", this, false, [] { return true; });
	NumberSetting tick_modulo = NumberSetting("Tick Modulo", this, 2, 10, 2, 1, [&] { return tick.gv<bool>(); });

	Timer(const std::string name, const mdl::MODULE_CATEGORY category);

	void on_enable(std::map<const std::string, JavaClass*>& classes) override;

	void on_disable(std::map<const std::string, JavaClass*>& classes) override;
};