#include "GUI.h"
#include <iostream>

GUI::GUI(Whiteout* whiteout) : whiteout(whiteout) { }

void GUI::draw_base() {
	const sf::Vector2f window_size(whiteout->window.getSize());
	sf::Text whiteout_w = font::text(whiteout->name, {30, 15 - font::height(font::mb, 18, true, whiteout->name, sf::Text::Bold) / 2}, font::mb, 18, sf::Text::Bold, Whiteout::base_color, 3);
	render::rect_outline_cutout(whiteout->window, sf::Vector2f(15, 15), sf::Vector2f(whiteout->window.getSize().x - 30, whiteout->window.getSize().y - 30), Whiteout::text_color, 1, 15, font::width(font::mb, 18, true, whiteout->name, sf::Text::Bold, 3) + 10);

	font::render(whiteout->window, whiteout_w);
}

void GUI::draw_modules() {
}

void GUI::on_mouse_event(const Key key) {
}