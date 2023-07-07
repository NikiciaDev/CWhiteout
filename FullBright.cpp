#include "FullBright.h"

FullBright::FullBright(const std::string name, const mdl::MODULE_CATEGORY category) : Module(name, category, NULL) { }

void FullBright::on_enable(std::map<const std::string, JavaClass*>& classes) {
	prev_gamma = -1;
}

void FullBright::on_call(std::map<const std::string, JavaClass*>& classes) {
	const float gamma = jenv_ptr->GetFloatField(get_game_settings()->instance, *get_game_settings()->jfields.find("gamma")->second);
	if (prev_gamma == -1) prev_gamma = gamma;
	if (brightness.gv<float>() != gamma) {
		jenv_ptr->SetFloatField(get_game_settings()->instance, *get_game_settings()->jfields.find("gamma")->second, brightness.gv<float>());
	}
}

void FullBright::on_disable(std::map<const std::string, JavaClass*>& classes) {
	jenv_ptr->SetFloatField(get_game_settings()->instance, *get_game_settings()->jfields.find("gamma")->second, prev_gamma);
}