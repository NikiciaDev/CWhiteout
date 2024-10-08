#include "AutoClicker.h"

AutoClicker::AutoClicker(const std::string name, const mdl::MODULE_CATEGORY category) : Module(name, category, 65536) {}

void AutoClicker::on_call(std::map<const std::string, JavaClass*>& classes) {
	const jvalue f{ jenv_ptr->GetFloatField(get_timer()->instance, *get_timer()->jfields.find("render_partial_ticks")->second) };
	jenv_ptr->CallVoidMethodA(get_entity_renderer()->instance, *get_entity_renderer()->jmethods.find("get_mouse_over")->second, &f);
	jfieldID id = jenv_ptr->GetFieldID(get_moving_object_position()->jclass, "a", "Lauh$a;"); // Only works when the player has enterd a world once!
	unsigned short eval = get_ev("auh$a", jenv_ptr->GetObjectField(get_moving_object_position()->instance, id));
	
	//jobject hitresult_j = jenv_ptr->CallObjectMethod(get_moving_object_position()->instance, *get_moving_object_position()->jmethods.find("to_string")->second);
	//std::string hitresult = jobj_to_string(hitresult_j);
	//const bool hit_type_block = (hitresult.find("BLOCK") != std::string::npos);
	//const bool hit_type_entitiy = (hitresult.find("ENTITY") != std::string::npos);

	if (GetAsyncKeyState(VK_LBUTTON) < 0 && this->random_left.gv<int>() > 0) {
		if (delay.ii()) {
			delay.sv(this->left_cps.gv<int>() + rndm.intg<int>(-(this->random_left.gv<int>()), this->random_left.gv<int>()));
		}

		if (delay.gv() <= 0) delay.sv(std::any_cast<int>(left_cps.gv<int>()));
		if (clock.has_time_elapsed(std::chrono::milliseconds(1000 / delay.gv()))) {
			jenv_ptr->CallVoidMethod(get_minecraft()->instance, *get_minecraft()->jmethods.find("click_mouse")->second);
			clock.reset();
			delay.sv(this->left_cps.gv<int>() + rndm.intg<int>(-(this->random_left.gv<int>()), this->random_left.gv<int>()));
		}
	}

	if (GetAsyncKeyState(VK_RBUTTON) < 0 && this->random_right.gv<int>() > 0) {
		if (delay.ii()) {
			delay.sv(this->random_right.gv<int>() + rndm.intg<int>(-(this->random_right.gv<int>()), this->random_right.gv<int>()));
		}

		if (delay.gv() <= 0) delay.sv(this->random_right.gv<int>());
		if (clock.has_time_elapsed(std::chrono::milliseconds(1000 / delay.gv()))) {
			jenv_ptr->CallVoidMethod(get_minecraft()->instance, *get_minecraft()->jmethods.find("right_click_mouse")->second);
			clock.reset();
		}
	}

	if (change_rcd_delay.gv<bool>() && rcd_delay.gv<int>() != rcd_delay.mx<int>()) {
		jenv_ptr->SetIntField(classes.find("Minecraft")->second->instance, *classes.find("Minecraft")->second->jfields.find("right_click_delay_timer")->second, rcd_delay.gv<int>());
	}
}