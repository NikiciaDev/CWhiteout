#include "Whiteout.h"

std::string Whiteout::name = "Whiteout";
std::string Whiteout::build = "b0.0";
std::string Whiteout::name_build = "Whiteout | b0.0";
sf::Color Whiteout::bg_color = sf::Color(15, 15, 15);
sf::Color Whiteout::base_color = sf::Color(110, 69, 56);
sf::Color Whiteout::text_color = sf::Color(225, 225, 225);

Whiteout::Whiteout(const std::string title, const unsigned short antialiasing_level, const unsigned short width, const unsigned short height) {
    sf::ContextSettings settings;
    settings.antialiasingLevel = antialiasing_level;
    this->window.create(sf::VideoMode(width, height), title, sf::Style::Default, settings);
    window.setFramerateLimit(60);
}

Whiteout::~Whiteout() { }

void Whiteout::dispatch_keypress(const Key key, const bool ext) {
    if (ext) {
        pressed_keys_ext.push_back(key);
        return;
    }
    pressed_keys.push_back(key);
}

bool Whiteout::poll_keypresses(Key& key, const bool ext) {
    if (!ext) {
        if (pressed_keys.size() <= 0) return false;
        key = pressed_keys[0];
        pressed_keys.erase(pressed_keys.begin());
    } else {
        if (pressed_keys_ext.size() <= 0) return false;
        key = pressed_keys_ext[0];
        pressed_keys_ext.erase(pressed_keys_ext.begin());
    }
    return true;
}
