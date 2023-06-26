#include "Whiteout.h"

std::string Whiteout::name = "Whiteout";
std::string Whiteout::build = "b0.0";
std::string Whiteout::name_build = "Whiteout | b0.0";
sf::Color Whiteout::bg_color = sf::Color(20, 20, 20);
sf::Color Whiteout::base_color = sf::Color(110, 69, 56);
sf::Color Whiteout::sm_base_color = sf::Color(255, 255, 255);

Whiteout::Whiteout(const std::string title, const unsigned short antialiasing_level, const unsigned short width, const unsigned short height) {
    sf::ContextSettings settings;
    settings.antialiasingLevel = antialiasing_level;
    this->window.create(sf::VideoMode(width, height), title, sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(60);
}

Whiteout::~Whiteout() { }

void Whiteout::dispatch_keypress(const unsigned long long keycode, const bool ext) {
    if (ext) {
        pressed_keys_ext.push_back(keycode);
        return;
    }
    pressed_keys.push_back(keycode);
}

bool Whiteout::poll_keypresses(unsigned long long& key, const bool ext) {
    if (!ext) {
        if (pressed_keys.size() <= 0) return false;
        key = *(pressed_keys.end() - 1);
        pressed_keys.erase(pressed_keys.begin());
    } else {
        if (pressed_keys_ext.size() <= 0) return false;
        key = *(pressed_keys_ext.end() - 1);
        pressed_keys_ext.pop_back();
    }
    return true;
}
