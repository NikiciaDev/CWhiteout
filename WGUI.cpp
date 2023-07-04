#include "WGUI.h"

WGUI::WGUI(const std::string name, const mdl::MODULE_CATEGORY category) : Module(name, category, NULL) { }

void WGUI::on_call(std::map<const std::string, JavaClass*>& classes) {
	if (Whiteout::base_color != base_color.gv<sf::Color>()) {
		Whiteout::base_color = base_color.gv<sf::Color>();
	}
}