#include "WindowUtil.h"

sf::RenderWindow* wul::create_window(const std::string title, const unsigned short antialiasing_level, const unsigned short width, const unsigned short height) {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 2;
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Titlebar | sf::Style::Close, settings);
    window->setFramerateLimit(60);
    return window;
}