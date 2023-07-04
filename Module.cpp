#include "Module.h"

Module::Module(const std::string name, const mdl::MODULE_CATEGORY category, const unsigned long long default_keybind) : name(name), category(category), keybind(default_keybind) {
	init_kb_string_represenation(default_keybind, keybind_s_rep);
}

void Module::on_call(std::map<const std::string, JavaClass*>& classes) { }

void Module::on_enable(std::map<const std::string, JavaClass*>& classes) { }

void Module::on_disable(std::map<const std::string, JavaClass*>& classes) { }

void Module::on_keypress(std::map<const std::string, JavaClass*>& classes) {
	is_active = !is_active;
	if (!is_active) {
		on_disable(classes);
	} else {
		on_enable(classes);
	}
}

void Module::init_kb_string_represenation(unsigned long long keycode, std::string& string) {
	string = "[";
	if (keycode == NULL) {
		string += "N/A";
	} else if (keycode == 1) {
		string += "MB1";
	} else if (keycode == 2) {
		string += "MB2";
	} else if (keycode == 4) {
		string += "MWU";
	} else if (keycode == 5) {
		string += "MWD";
	} else if (keycode == 65536) {
		string += "XB1";
	} else if (keycode == 131072) {
		string += "XB2";
	} else {
		string += (char) keycode;
	}
	string += "]";
}

Module::~Module() {
	std::for_each(drawables.begin(), drawables.end(), [](DrawableSetting* d) {
		delete d;
	});
}