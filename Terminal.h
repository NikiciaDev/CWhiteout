#pragma once
#include <map>
#include "SFML/Graphics.hpp"
#include "FontRenderer.h"
#include "Clock.h"
#include "SentCommand.h"
#include "Command.h"

namespace CommandManager {
	extern std::map<const std::string, Command*> commands;
}

class Terminal final {
private:
	std::string current_in{ "" };
	Clock<std::chrono::milliseconds> clock;
	bool display_a_c{ false };

public:
	Whiteout& whiteout;
	sf::Vector2f input_pos{ 35, 35 };
	std::vector<SentCommand> sent_commands; // Causes when it held 50 commands once a weird Abort has been calles on exit!

	Terminal(Whiteout& whiteout);

	void draw();

	void on_key_press(const Key key);
};