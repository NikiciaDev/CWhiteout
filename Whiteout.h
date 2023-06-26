#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Whiteout final {
public:
	static std::string name;
	static std::string build;
	static std::string name_build;
	static sf::Color bg_color;
	static sf::Color base_color;
	static sf::Color sm_base_color;
	sf::RenderWindow window;
	std::vector<unsigned long long> pressed_keys, pressed_keys_ext;

	Whiteout(const std::string title, const unsigned short antialiasing_level, const unsigned short width, const unsigned short height);

	~Whiteout();

	void dispatch_keypress(const unsigned long long keycode, const bool ext);

	bool poll_keypresses(unsigned long long& key, const bool ext);
};