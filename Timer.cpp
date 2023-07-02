#include "Timer.h"

Timer::Timer(const std::string name, const mdl::MODULE_CATEGORY category) : Module(name, category, NULL) {}

void Timer::on_enable(std::map<const std::string, JavaClass*>& classes) {
	jenv_ptr->SetFloatField(classes.find("Timer")->second->instance, *classes.find("Timer")->second->jfields.find("timer_speed")->second, speed.gv<double>());
}

void Timer::on_disable(std::map<const std::string, JavaClass*>& classes) {
	jenv_ptr->SetFloatField(classes.find("Timer")->second->instance, *classes.find("Timer")->second->jfields.find("timer_speed")->second, 1);
}