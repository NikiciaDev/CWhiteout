#include "AutoClicker.h"

AutoClicker::AutoClicker(const std::string name, const mdl::MODULE_CATEGORY category) : Module(name, category, 65536) {}

void AutoClicker::on_call(std::map<const std::string, JavaClass*>& classes) {
	if (GetAsyncKeyState(VK_LBUTTON) < 0 && left_cps.value > 0) {
		if (delay.ii()) {
			delay.sv(left_cps.value + rndm.intg<short>(-(this->random_left.value), this->random_left.value));
		}

		if (delay.gv() <= 0) delay.sv(left_cps.value);
		if (clock.has_time_elapsed(std::chrono::milliseconds(1000 / delay.gv()))) {
			jenv_ptr->CallVoidMethod(classes.find("Minecraft")->second->instance, *classes.find("Minecraft")->second->jmethods.find("click_mouse")->second);
			clock.reset();
			delay.sv(left_cps.value + rndm.intg<short>(-(this->random_left.value), this->random_left.value));
		}
	}

	if (GetAsyncKeyState(VK_RBUTTON) < 0 && right_cps.value > 0) {
		if (delay.ii()) {
			delay.sv(right_cps.value + rndm.intg<short>(-(this->random_right.value), this->random_right.value));
		}

		if (delay.gv() <= 0) delay.sv(right_cps.value);
		if (clock.has_time_elapsed(std::chrono::milliseconds(1000 / delay.gv()))) {
			jenv_ptr->CallVoidMethod(classes.find("Minecraft")->second->instance, *classes.find("Minecraft")->second->jmethods.find("right_click_mouse")->second);
			clock.reset();
		}
	}

	if (change_rcd_delay.value && rcd_delay.value != rcd_delay.max) {
		jenv_ptr->SetIntField(classes.find("Minecraft")->second->instance, *classes.find("Minecraft")->second->jfields.find("right_click_delay_timer")->second, rcd_delay.value);
	}
}