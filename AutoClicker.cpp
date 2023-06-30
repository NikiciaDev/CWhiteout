#include "AutoClicker.h"

AutoClicker::AutoClicker(const std::string name, const mdl::MODULE_CATEGORY category) : Module(name, category, 65536) {}

void AutoClicker::on_call(std::map<const std::string, JavaClass*>& classes) {
	if (GetAsyncKeyState(VK_LBUTTON) < 0 && this->random_left.vl<short>() > 0) {
		if (delay.ii()) {
			delay.sv(this->left_cps.vl<short>() + rndm.intg<short>(-(this->random_left.vl<short>()), this->random_left.vl<short>()));
		}

		if (delay.gv() <= 0) delay.sv(std::any_cast<short>(left_cps.value));
		if (clock.has_time_elapsed(std::chrono::milliseconds(1000 / delay.gv()))) {
			jenv_ptr->CallVoidMethod(classes.find("Minecraft")->second->instance, *classes.find("Minecraft")->second->jmethods.find("click_mouse")->second);
			clock.reset();
			delay.sv(this->left_cps.vl<short>() + rndm.intg<short>(-(this->random_left.vl<short>()), this->random_left.vl<short>()));
		}
	}

	if (GetAsyncKeyState(VK_RBUTTON) < 0 && this->random_right.vl<short>() > 0) {
		if (delay.ii()) {
			delay.sv(this->random_right.vl<short>() + rndm.intg<short>(-(this->random_right.vl<short>()), this->random_right.vl<short>()));
		}

		if (delay.gv() <= 0) delay.sv(this->random_right.vl<short>());
		if (clock.has_time_elapsed(std::chrono::milliseconds(1000 / delay.gv()))) {
			jenv_ptr->CallVoidMethod(classes.find("Minecraft")->second->instance, *classes.find("Minecraft")->second->jmethods.find("right_click_mouse")->second);
			clock.reset();
		}
	}

	if (change_rcd_delay.value && rcd_delay.vl<short>() != rcd_delay.mx<short>()) {
		jenv_ptr->SetIntField(classes.find("Minecraft")->second->instance, *classes.find("Minecraft")->second->jfields.find("right_click_delay_timer")->second, rcd_delay.vl<float>());
	}
}