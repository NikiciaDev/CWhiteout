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
	char keybind{ NULL };
	std::vector<SettingBase*> settings; // These pointers should be allocated on the stack to prevent memory leaks.

	Module(const std::string name, const mdl::MODULE_CATEGORY category);

	virtual void on_call(std::map<const std::string, JavaClass*>& classes);

	virtual void on_draw(const Whiteout& whiteout);

	virtual void on_enable(const Whiteout& whiteout);

	virtual void on_disable(const Whiteout& whiteout);

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