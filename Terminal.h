#pragma once
#include <map>
#include "SFML/Graphics.hpp"
#include "FontRenderer.h"
#include "Clock.h"
#include "SentCommand.h"
#include "Module.h"
#include "Command.h"
#include "CategorySelectionButton.h"

namespace CommandManager {
	extern std::map<const std::string, Command*> commands;
}

class Terminal final {
private:
	std::string current_in{ "" };
	Clock<std::chrono::milliseconds> clock;
	bool display_a_c{ false };
	CategorySelectionButton& csb;

public:
	Whiteout& whiteout;
	sf::Vector2f input_pos{ 35, 35 };
	std::vector<SentCommand> sent_commands;

	Terminal(Whiteout& whiteout, CategorySelectionButton& csb);

	void draw();

	void on_key_press(const Key key);

	void clean();
};