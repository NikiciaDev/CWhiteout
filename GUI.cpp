#include "GUI.h"

GUI::GUI(Whiteout* whiteout) : whiteout(whiteout) { }

void GUI::draw_base() {
	const sf::Vector2u window_size(whiteout->window.getSize());
	const sf::View view(whiteout->view);

	render::rect_outline(whiteout->window, whiteout->window.mapPixelToCoords(sf::Vector2i(30, 30)), sf::Vector2f(window_size.x - 60, window_size.y - 60), Whiteout::bg_color, 50);

	sf::Text whiteout_t = font::text(whiteout->name, whiteout->window.mapPixelToCoords(sf::Vector2i(35, 15 - font::height(font::mb, 18, true, whiteout->name, sf::Text::Bold) / 2)), font::mb, 18, sf::Text::Bold, Whiteout::base_color, 5);
	render::rect_outline_cutout(whiteout->window, whiteout->window.mapPixelToCoords(sf::Vector2i(15, 15)), sf::Vector2f(window_size.x - 30, window_size.y - 30), Whiteout::text_color, 1, 15, font::width(whiteout_t) + 10);

	font::render(whiteout->window, whiteout_t);
}

void GUI::draw_modules() {
}

void GUI::on_mouse_event(const Key key) {
	switch (key.keycode) {
	default:
		break;
	case 4:
		whiteout->view.move(0, 25);
		whiteout->window.setView(whiteout->view);
		break;
	case 5:
		whiteout->view.move(0, -25);
		whiteout->window.setView(whiteout->view);
		break;
	}
}