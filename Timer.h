#pragma once
#include "Module.h"
#include "NumberSetting.h"
#include "BooleanSetting.h"

class Timer final : public Module {
public:
	const NumberSetting<float> speed = NumberSetting<float>("Timer Speed", this, 0.1f, 10, 1, 0.025, [] { return true; });
	const BooleanSetting tick = BooleanSetting("Tick", this, false, [] { return true; });
	const NumberSetting<short> tick_modulo = NumberSetting<short>("Tick Modulo", this, 2, 10, 2, 1, [&] { return tick.value; });

	Timer(const std::string name, const mdl::MODULE_CATEGORY category);

	void on_enable(std::map<const std::string, JavaClass*>& classes) override;

	void on_disable(std::map<const std::string, JavaClass*>& classes) override;
};