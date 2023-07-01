#pragma once
#include <string>
#include <jni.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include "JavaClass.h"
#include "ConsoleUtil.h"
#include "Whiteout.h"

class Setting; // Avoid circular dependency.
namespace mdl {
	enum MODULE_CATEGORY;
}
extern JavaVM* jvm_ptr;
extern JNIEnv* jenv_ptr;

class Module {
public:
	static std::vector<std::string> mdcn;
	static std::vector<sf::Color> mdcc;

	bool is_active{ false };
	const std::string name;
	const mdl::MODULE_CATEGORY category;
	unsigned long long keybind{ NULL };
	std::string keybind_s_rep{ "" };
	std::vector<Setting*> settings; // These pointers should be allocated on the stack to prevent memory leaks.

	Module(const std::string name, const mdl::MODULE_CATEGORY category, const unsigned long long default_keybind);

	virtual void on_call(std::map<const std::string, JavaClass*>& classes);

	virtual void on_enable(std::map<const std::string, JavaClass*>& classes);

	virtual void on_disable(std::map<const std::string, JavaClass*>& classes);

	void on_keypress(std::map<const std::string, JavaClass*>& classes);

	static void init_kb_string_represenation(unsigned long long keycode, std::string& string);
};

namespace mdl {
	enum MODULE_CATEGORY {
		TERMINAL,
		COMBAT,
		MOVEMENT,
		PLAYER,
		VISUAL,
		EXPLOIT,
		UNDECLARED
	};
}