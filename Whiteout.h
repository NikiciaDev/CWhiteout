#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Key.h"

class Whiteout final {
public:
	static std::string name;
	static std::string build;
	static std::string name_build;
	static sf::Color bg_color;
	static sf::Color base_color;
	static sf::Color text_color;
	sf::RenderWindow window;
	std::vector<Key> pressed_keys, pressed_keys_ext;
	sf::View view;

	Whiteout(const std::string title, const unsigned short antialiasing_level, const unsigned short width, const unsigned short height);

	~Whiteout();

	void dispatch_keypress(Key key, const bool ext);

	bool poll_keypresses(Key& key, const bool ext);
};