#include "GUI.h"

GUI::GUI(Whiteout* whiteout) : whiteout(whiteout), csb(*whiteout, sf::FloatRect(0, 0, 0, 0)), terminal(*whiteout, csb) {}

void GUI::draw_base() {
	if (csb.current == mdl::MODULE_CATEGORY::UNDECLARED) return;
	const sf::Vector2u window_size(whiteout->window.getSize());
	const sf::View view(whiteout->view);
	const sf::Text csb_text = csb.get_draw_text();

	// Scrolling outline.
	render::rect_outline(whiteout->window, whiteout->window.mapPixelToCoords(sf::Vector2i(30, 30)), sf::Vector2f(window_size.x - 60, window_size.y - 60), Whiteout::bg_color, 50);

	sf::Vector2f pos_csb(whiteout->window.getSize().x - 30 - 5 - font::width(csb_text), 15 - font::height(Module::mdcn[csb.current], font::mb, 24, true, sf::Text::Bold) / 2);
	sf::Text whiteout_t = font::text(whiteout->name, whiteout->window.mapPixelToCoords(sf::Vector2i(35, 15 - font::height(whiteout->name, font::meb, 24, true, sf::Text::Bold) / 2)), sf::Vector2f(1, 1), font::meb, 24, sf::Text::Bold, Whiteout::base_color, 5);
	render::rect_outline_dcutout(whiteout->window, whiteout->window.mapPixelToCoords(sf::Vector2i(15, 15)), sf::Vector2f(window_size.x - 30, window_size.y - 30), Whiteout::text_color, 15, font::width(whiteout_t) + 10,
		pos_csb.x - 15 - 5, font::width(csb_text) + 10);

	csb.draw();
	font::render(whiteout->window, whiteout_t);
}

void GUI::draw_modules() {
	if (csb.current == mdl::MODULE_CATEGORY::TERMINAL) {
		terminal.draw();
	} else {
		sf::Vector2u window_size = whiteout->window.getSize();
		sf::Vector2f scale(window_size.x / 1000.f, window_size.y / 600.f);
		sf::Vector2f scale_t(1, 1);
		render::rect(whiteout->window, sf::Vector2f((window_size.x / 2) - 0.5f, -9999), sf::Vector2f(1, 9999 * 2), Whiteout::text_color);

		float c1_pos_y{ 45 }, c2_pos_y{ 45 };
		unsigned short s{ 0 };
		for (Module* m : ModuleManager::module_vec_by_cat(csb.current)) {
			float x = s % 2 == 0 ? 45 : (window_size.x / 2) - 0.5f + 30;
			float& y = s % 2 == 0 ? c1_pos_y : c2_pos_y;
			float height{ 100 }; // Change to 0 after module setting drawing has been implemented!



			sf::Text name_t = font::text(m->name, sf::Vector2f(x + 15, y - font::height(m->name, font::mm, 18) * 0.65f), scale_t, font::mm, 18, sf::Text::Regular, Module::mdcc[csb.current]);
			render::rect_outline_cutout(whiteout->window, sf::Vector2f(x, y), sf::Vector2f((window_size.x / 2) - 0.5f - 60 - 15, height), Whiteout::text_color, 15, font::width(name_t, true));
			font::render(whiteout->window, name_t);

			y += height;
		}

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
