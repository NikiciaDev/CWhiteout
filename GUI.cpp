#include "GUI.h"

GUI::GUI(Whiteout* whiteout) : whiteout(whiteout), selected_category(mdl::MODULE_CATEGORY::COMBAT), csb(*whiteout, sf::FloatRect(0, 0, 0, 0)) {}

void GUI::draw_base() {
	const sf::Vector2u window_size(whiteout->window.getSize());
	const sf::View view(whiteout->view);
	const sf::Text csb_text = csb.get_draw_text();

	// Scrolling outline.
	render::rect_outline(whiteout->window, whiteout->window.mapPixelToCoords(sf::Vector2i(30, 30)), sf::Vector2f(window_size.x - 60, window_size.y - 60), Whiteout::bg_color, 50);

	sf::Vector2f pos_csb(whiteout->window.getSize().x - 30 - 5 - font::width(font::mb, 16, false, Module::mdcn[csb.current], sf::Text::Bold, 5), 15 - font::height(font::mb, 16, true, Module::mdcn[csb.current], sf::Text::Bold) / 2);
	sf::Text whiteout_t = font::text(whiteout->name, whiteout->window.mapPixelToCoords(sf::Vector2i(35, 15 - font::height(font::meb, 18, true, whiteout->name, sf::Text::Bold) / 2)), font::meb, 18, sf::Text::Bold, Whiteout::base_color, 5);
	render::rect_outline_dcutout(whiteout->window, whiteout->window.mapPixelToCoords(sf::Vector2i(15, 15)), sf::Vector2f(window_size.x - 30, window_size.y - 30), Whiteout::text_color, 1, 15, font::width(whiteout_t) + 10,
		pos_csb.x - 15 - 5, font::width(csb_text) + 10);

	csb.draw();
	font::render(whiteout->window, whiteout_t);
}

void GUI::draw_modules() {
}

void GUI::on_mouse_event(const Key key) {
	switch (key.keycode) {
	default:
		break;
	case 1:
	case 2:
		csb.on_mouse(key);
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