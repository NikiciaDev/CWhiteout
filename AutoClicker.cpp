#include "AutoClicker.h"

AutoClicker::AutoClicker(const std::string name, const mdl::MODULE_CATEGORY category) : Module(name, category) { }

void AutoClicker::on_call(std::map<const std::string, JavaClass*>& classes) {
	if (GetAsyncKeyState(VK_LBUTTON) < 0 && left_cps.value > 0) {
		short s = left_cps.value + rul::rndm_num_ir<short>(-(this->random_left.value), this->random_left.value, clock.last.count());
		if (clock.has_time_elapsed(std::chrono::milliseconds(1000 / s))) {
			jenv_ptr->CallVoidMethod(classes.find("Minecraft")->second->instance, *classes.find("Minecraft")->second->jmethods.find("click_mouse")->second);
			clock.reset();
		}
	}

	if (GetAsyncKeyState(VK_RBUTTON) < 0 && right_cps.value > 0) {
		short s = right_cps.value + rul::rndm_num_ir<short>(-(this->random_right.value), this->random_right.value, clock.last.count());
		if (clock.has_time_elapsed(std::chrono::milliseconds(1000 / s))) {
			jenv_ptr->CallVoidMethod(classes.find("Minecraft")->second->instance, *classes.find("Minecraft")->second->jmethods.find("right_click_mouse")->second);
			clock.reset();
		}
	}

	if (change_rcd_delay.value && rcd_delay.value != rcd_delay.max) {
		jenv_ptr->SetIntField(classes.find("Minecraft")->second->instance, *classes.find("Minecraft")->second->jfields.find("right_click_delay_timer")->second, rcd_delay.value);
	}
}