#pragma once
#include "Module.h"
#include "NumberSetting.h"
#include "BasicUtil.h"

class FullBright final : public Module {
private:
	float prev_gamma{ -1 };

public:
	NumberSetting brightness = NumberSetting("Brightness", this, 0.f, 10.f, 10.f, 0.5f, num::Type::F, [] { return true; });

	FullBright(const std::string name, const mdl::MODULE_CATEGORY category);

	void on_enable(std::map<const std::string, JavaClass*>& classes);

	void on_disable(std::map<const std::string, JavaClass*>& classes);

	void on_call(std::map<const std::string, JavaClass*>& classes) override;
};