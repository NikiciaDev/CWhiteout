#include "GUI.h"

GUI::GUI(Whiteout* whiteout) : whiteout(whiteout), csb(*whiteout, sf::FloatRect(0, 0, 0, 0)), terminal(*whiteout, csb) {}

void GUI::draw_base() {
	if (csb.current == mdl::MODULE_CATEGORY::UNDECLARED) return;
	const sf::Vector2u window_size(whiteout->window.getSize());
	const sf::View view(whiteout->view);
	const sf::Text csb_text = csb.get_draw_text();

	// Scrolling outline.
	render::rect_outline(whiteout->window, whiteout->window.mapPixelToCoords(sf::Vector2i(30, 30)), sf::Vector2f(window_size.x - 60, window_size.y - 60), Whiteout::bg_color, 50);

	sf::Vector2f pos_csb(whiteout->window.getSize().x - 30 - 5 - font::width(Module::mdcn[csb.current], font::mb, 16, false, sf::Text::Bold, 5), 15 - font::height(Module::mdcn[csb.current], font::mb, 16, true, sf::Text::Bold) / 2);
	sf::Text whiteout_t = font::text(whiteout->name, whiteout->window.mapPixelToCoords(sf::Vector2i(35, 15 - font::height(whiteout->name, font::meb, 18, true, sf::Text::Bold) / 2)), font::meb, 18, sf::Text::Bold, Whiteout::base_color, 5);
	render::rect_outline_dcutout(whiteout->window, whiteout->window.mapPixelToCoords(sf::Vector2i(15, 15)), sf::Vector2f(window_size.x - 30, window_size.y - 30), Whiteout::text_color, 1, 15, font::width(whiteout_t) + 10,
		pos_csb.x - 15 - 5, font::width(csb_text) + 10);

	csb.draw();
	font::render(whiteout->window, whiteout_t);
}

void GUI::draw_modules() {
	switch (csb.current) {
	case mdl::MODULE_CATEGORY::TERMINAL:
		terminal.draw();
		break;
	}
}

void GUI::on_key_event(const Key key) {
	switch (key.keycode) {
	default:
		if (csb.current == mdl::MODULE_CATEGORY::TERMINAL) {
			terminal.on_key_press(key);
		}
		break;
	case 1:
	case 2:
		if (csb.on_mouse(key)) {
			if (csb.current == mdl::MODULE_CATEGORY::TERMINAL) {
				whiteout->view.move(0, terminal.input_pos.y - 30);
			}
			whiteout->window.setView(whiteout->view);
			break;
		}
		break;
	case 3:

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
