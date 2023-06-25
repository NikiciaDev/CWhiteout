#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include "ConsoleUtil.h"
#include "Whiteout.h"

class SettingBase; // Avoid circular dependency.
enum MODULE_CATEGORY;

class Module {
public:
	const std::string name;
	const MODULE_CATEGORY category;
	std::vector<SettingBase*> settings; // These should be allocated on the stack to prevent memory leaks.

	Module(const std::string name, const MODULE_CATEGORY category);

	virtual void on_call();

	virtual void on_draw(const Whiteout& whiteout);

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