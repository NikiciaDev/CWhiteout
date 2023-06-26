#pragma once
#include <string>
#include <jni.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include "JavaClass.h"
#include "ConsoleUtil.h"
#include "Whiteout.h"

class SettingBase; // Avoid circular dependency.
namespace mdl {
	enum MODULE_CATEGORY;
}
extern JavaVM* jvm_ptr;
extern JNIEnv* jenv_ptr;

class Module {
public:
	bool is_active{ false };
	const std::string name;
	const mdl::MODULE_CATEGORY category;
	unsigned long long keybind{ NULL };
	std::string keybind_s_rep{ "" };
	std::vector<SettingBase*> settings; // These pointers should be allocated on the stack to prevent memory leaks.

	Module(const std::string name, const mdl::MODULE_CATEGORY category, const unsigned long long default_keybind);

	virtual void on_call(std::map<const std::string, JavaClass*>& classes);

	virtual void on_enable(std::map<const std::string, JavaClass*>& classes);

	virtual void on_disable(std::map<const std::string, JavaClass*>& classes);

	void on_keypress(std::map<const std::string, JavaClass*>& classes);

	static sf::Color get_module_color(const Module& module);
};

namespace mdl {
	enum MODULE_CATEGORY {
		UNDECLARED,
		COMBAT,
		MOVEMENT,
		PLAYER,
		VISUAL,
		EXPLOIT
	};
}