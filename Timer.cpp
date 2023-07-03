#include "Timer.h"

Timer::Timer(const std::string name, const mdl::MODULE_CATEGORY category) : Module(name, category, NULL) {}

void Timer::on_call(std::map<const std::string, JavaClass*>& classes) {
	const int ticks_existed = jenv_ptr->GetIntField(classes.find("EntityPlayerSp")->second->instance, *classes.find("EntityPlayerSp")->second->jfields.find("ticks_existed")->second);
	const float timer_speed = jenv_ptr->GetFloatField(classes.find("Timer")->second->instance, *classes.find("Timer")->second->jfields.find("timer_speed")->second);
	const float desired_speed = speed.gv<float>();

	if (tick.gv<bool>()) {
		if (ticks_existed % tick_modulo.gv<int>() == 0) {
			jenv_ptr->SetFloatField(classes.find("Timer")->second->instance, *classes.find("Timer")->second->jfields.find("timer_speed")->second, desired_speed);
		} else {
			jenv_ptr->SetFloatField(classes.find("Timer")->second->instance, *classes.find("Timer")->second->jfields.find("timer_speed")->second, 1.f);
		}
	} else if (timer_speed != desired_speed) {
		jenv_ptr->SetFloatField(classes.find("Timer")->second->instance, *classes.find("Timer")->second->jfields.find("timer_speed")->second, desired_speed);
	}
}

void Timer::on_disable(std::map<const std::string, JavaClass*>& classes) {
	jenv_ptr->SetFloatField(classes.find("Timer")->second->instance, *classes.find("Timer")->second->jfields.find("timer_speed")->second, 1.f);
}