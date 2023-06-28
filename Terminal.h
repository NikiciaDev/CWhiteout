#pragma once
#include <map>
#include "SFML/Graphics.hpp"
#include "Command.h"
#include "FontRenderer.h"
#include "Clock.h"

class Terminal final {
private:
	std::map<const std::string, const Command*> commands{ };
	std::string current_in{ "" };
	Clock<std::chrono::milliseconds> clock;
	bool display_a_c{ false };

public:
	Whiteout& whiteout;
	sf::Vector2f input_pos{ 35, 35 };

	Terminal(Whiteout& whiteout);

	void draw();

	void on_key_press(const Key key);
};