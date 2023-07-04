#include "GUI.h"

GUI::GUI(Whiteout* whiteout) : whiteout(whiteout), csb(*whiteout, sf::FloatRect(0, 0, 0, 0)), terminal(*whiteout, csb) {
	for (unsigned short m = mdl::MODULE_CATEGORY::COMBAT; m < mdl::MODULE_CATEGORY::UNDECLARED; m++) {
		for (Module* mod : ModuleManager::module_vec_by_cat(static_cast<mdl::MODULE_CATEGORY>(m))) {
			for (Setting* s : mod->settings) {
				DrawableSetting* d; // These get cleaned up in the module destrcutor.
				switch (s->type) {
				case setting::Type::BOOLEAN:
					d = new DrawableBool(sf::Vector2f(0, 0), s->type, static_cast<BooleanSetting*>(s), *whiteout);
					mod->drawables.push_back(d);
					break;
				case setting::Type::COLOR:
					d = new DrawableColor(sf::Vector2f(0, 0), s->type, static_cast<ColorSetting*>(s), *whiteout);
					mod->drawables.push_back(d);
					break;
				case setting::Type::MODE:
					d = new DrawableMode(sf::Vector2f(0, 0), s->type, static_cast<ModeSetting*>(s), *whiteout);
					mod->drawables.push_back(d);
					break;
				case setting::Type::NUMBER:
					d = new DrawableNumber(sf::Vector2f(0, 0), s->type, static_cast<NumberSetting*>(s), *whiteout);
					mod->drawables.push_back(d);
					break;
				case setting::Type::STRING:
					d = new DrawableString(sf::Vector2f(0, 0), s->type, static_cast<StringSetting*>(s), *whiteout);
					mod->drawables.push_back(d);
					break;
				}
			}
		}
	}
}

void GUI::draw_base() {
	if (csb.current == mdl::MODULE_CATEGORY::UNDECLARED) return;
	const sf::Vector2u window_size(whiteout->window.getSize());
	const sf::View view(whiteout->view);
	const sf::Text csb_text = csb.get_draw_text();

	// Scrolling outline.
	render::rect_outline(whiteout->window, whiteout->window.mapPixelToCoords(sf::Vector2i(30, 30)), sf::Vector2f(window_size.x - 60, window_size.y - 60), Whiteout::bg_color, 50);

	sf::Vector2f pos_csb(whiteout->window.getSize().x - 30 - 5 - font::width(csb_text), 15 - font::height(Module::mdcn[csb.current], font::mb, 24, true, sf::Text::Bold) / 2);
	sf::Text whiteout_t = font::text(whiteout->name, whiteout->window.mapPixelToCoords(sf::Vector2i(35, 15 - font::height(whiteout->name, font::meb, 24, true, sf::Text::Bold) / 2)), font::meb, 24, sf::Text::Bold, Whiteout::base_color, 5);
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
		render::rect(whiteout->window, sf::Vector2f((window_size.x / 2) - 0.5f, -9999), sf::Vector2f(1, 9999 * 2), Whiteout::text_color);

		float c1_pos_y{ 45 }, c2_pos_y{ 45 };
		unsigned short count{ 0 };
		
		for (Module* m : ModuleManager::module_vec_by_cat(csb.current)) {
			float x = count % 2 == 0 ? 45 : (window_size.x / 2) - 0.5f + 30;
			float& y = count % 2 == 0 ? c1_pos_y : c2_pos_y;
			float height{ 10 };
			sf::Vector2f outline_r_w((window_size.x / 2) - 0.5f - 60 - 15, height);

			for (DrawableSetting* s : m->drawables) {
				s->pos = sf::Vector2f(x + 15, y + height);
				s->draw(height, outline_r_w);
			}
			height += 10 - 5;
			
			outline_r_w.y = height;
			sf::Text name_t = font::text(m->name, sf::Vector2f(x + 30, y - font::height(m->name, font::mm, 22) * 0.65f), font::mm, 22, sf::Text::Regular, m->is_active ? Module::mdcc[csb.current] : Whiteout::text_color);
			sf::Text bind_t = font::text(m->keybind_s_rep, sf::Vector2f(x + outline_r_w.x - 30 - font::width(m->keybind_s_rep, font::mr, 15), y - font::height(m->keybind_s_rep, font::mm, 15) * 0.65f), font::mr, 15);
			if (count % 2 == 0) {
				render::rect_outline_dcutout2(whiteout->window, sf::Vector2f(x, y), outline_r_w, Whiteout::text_color, 30, font::width(name_t, true), outline_r_w.x - 30 - font::width(bind_t), font::width(bind_t));
			} else {
				render::rect_outline_dcutout(whiteout->window, sf::Vector2f(x, y), outline_r_w, Whiteout::text_color, 30, font::width(name_t, true), outline_r_w.x - 30 - font::width(bind_t), font::width(bind_t));
			}
			font::render(whiteout->window, name_t);
			font::render(whiteout->window, bind_t);

			m_names.insert_or_assign(m, std::make_pair(sf::FloatRect(x, y, outline_r_w.x, outline_r_w.y), name_t.getGlobalBounds()));
			m_binds.insert_or_assign(m, bind_t.getGlobalBounds());
			y += height + 30;
			count++;
		}
	}
}

void GUI::on_key_event(const Key key) {
	sf::Vector2f mp(key.mouse_pos.x, key.mouse_pos.y);
	switch (key.keycode) {
	default:
		if (csb.current == mdl::MODULE_CATEGORY::TERMINAL) {
			terminal.on_key_press(key);
		} else {
			if (m_binding != nullptr) {
				if (key.keycode == 27) { // ESC
					m_binding->init_kb_string_represenation(m_binding->keybind, m_binding->keybind_s_rep);
					m_binding = nullptr;
					return;
				}
				m_binding->keybind = key.keycode;
				m_binding->init_kb_string_represenation(key.keycode, m_binding->keybind_s_rep);
				m_binding = nullptr;
			}
		}
		return;
	case 1:
	case 2:
	case 3:
		if (key.keycode != 3 && m_binding != nullptr) {
			m_binding->init_kb_string_represenation(m_binding->keybind, m_binding->keybind_s_rep);
			m_binding = nullptr;
			return;
		}
		if (key.keycode != 3) {
			if (csb.on_mouse(key)) {
				if (csb.current == mdl::MODULE_CATEGORY::TERMINAL) {
					whiteout->view.move(0, terminal.input_pos.y - 30);
				}
				whiteout->window.setView(whiteout->view);
				return;
			}

			for (const std::pair<Module*, sf::FloatRect>& p : m_binds) {
				if (p.second.contains(key.mouse_pos) && csb.current == p.first->category) {
					m_binding = p.first;
					m_binding->keybind_s_rep = "[?]";
					return;
				}
			}
		}

		for (const std::pair<Module*, std::pair<sf::FloatRect, sf::FloatRect>>& p : m_names) {
			if (key.keycode != 3 && csb.current == p.first->category && p.second.second.contains(mp)) {
				p.first->on_keypress(classes);
				return;
			}
			if (p.second.first.contains(mp)) {
				for (DrawableSetting* ds : p.first->drawables) {
					if (ds->on_event(key, csb.current)) return;
				}
			}
		}
		return;
	case 4:
		whiteout->view.move(0, 25);
		whiteout->window.setView(whiteout->view);
		return;
	case 5:
		whiteout->view.move(0, -25);
		whiteout->window.setView(whiteout->view);
		return;
	}
}
