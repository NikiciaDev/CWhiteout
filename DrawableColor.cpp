#include "DrawableColor.h"

DrawableColor::DrawableColor(const sf::Vector2f position, const setting::Type type, ColorSetting* setting, Whiteout& whiteout) : DrawableSetting(position, type, whiteout), setting(setting) {}

void DrawableColor::draw(float& height, sf::Vector2f outline_r_w) {
	if (!setting->dependency()) return;
	this->outline_r_w = outline_r_w;
	const float rec_w = font::height();

	sf::Text n_t = font::text(setting->name, pos);
	font::render(whiteout.window, n_t);
	color_rect.setPosition(sf::Vector2f(pos.x + outline_r_w.x - 20 - 10 - rec_w, pos.y + 2.5f));
	color_rect.setSize(sf::Vector2f(rec_w, rec_w));
	color_rect.setFillColor(setting->gv<sf::Color>());
	whiteout.window.draw(color_rect);

	sf::Vector2 _pos(pos.x - 5, pos.y + font::height(n_t) + 15);
	if (extened) {
		sf::VertexArray vertices(sf::PrimitiveType::Quads, 24);
		create_hue_vertecies(vertices, _pos, (outline_r_w.x - 20) / 6.0f, rec_w);
		bar_bounds.setPosition(_pos);
		bar_bounds.setSize(sf::Vector2f(outline_r_w.x - 20, rec_w));
		whiteout.window.draw(vertices);

		if (dragging_bar) {
			if (bar_bounds.getGlobalBounds().contains(liu::get_cursor_pos(true))) {
				hue_bar_x = liu::get_cursor_pos(true).x;
				sf::Texture texture;
				texture.create(whiteout.window.getSize().x, whiteout.window.getSize().y);
				texture.update(whiteout.window);
				sf::Image img = texture.copyToImage();
				setting->sv(img.getPixel(hue_bar_x, _pos.y + 3));
			} else {
				dragging_bar = false;
			}
		}

		if (hue_bar_x != 0) {
			render::rect_outline(whiteout.window, sf::Vector2f(hue_bar_x - 2, _pos.y - 2), sf::Vector2f(4, rec_w + 2), Whiteout::text_color, 2.f);
		}
		height += rec_w * 2;
	}

	height += rec_w;
}

bool DrawableColor::on_event(const Key key, const mdl::MODULE_CATEGORY current) {
	if (bounds_contain(key, setting, current)) {
		if (key.keycode == 3) return true;
		if (color_rect.getGlobalBounds().contains(key.mouse_pos)) {
			extened = !extened;
		}
		return true;
	} else if (extened) {
		if (bar_bounds.getGlobalBounds().contains(key.mouse_pos)) {
			dragging_bar = key.keycode != 3;
		}
		return true;
	}
	return false;
}

void DrawableColor::create_hue_vertecies(sf::VertexArray& vertices, const sf::Vector2f pos, const float width_per, const float height) {
	vertices[0].position = sf::Vector2f(pos.x, pos.y + height);
	vertices[1].position = sf::Vector2f(pos.x, pos.y);
	vertices[2].position = sf::Vector2f(pos.x + width_per, pos.y);
	vertices[3].position = sf::Vector2f(pos.x + width_per, pos.y + height);
	vertices[0].color = sf::Color::Red;
	vertices[1].color = sf::Color::Red;
	vertices[2].color = sf::Color::Yellow;
	vertices[3].color = sf::Color::Yellow;

	vertices[4].position = sf::Vector2f(pos.x + width_per, pos.y + height);
	vertices[5].position = sf::Vector2f(pos.x + width_per, pos.y);
	vertices[6].position = sf::Vector2f(pos.x + width_per * 2, pos.y);
	vertices[7].position = sf::Vector2f(pos.x + width_per * 2, pos.y + height);
	vertices[4].color = sf::Color::Yellow;
	vertices[5].color = sf::Color::Yellow;
	vertices[6].color = sf::Color::Green;
	vertices[7].color = sf::Color::Green;

	vertices[8].position = sf::Vector2f(pos.x + width_per * 2, pos.y + height);
	vertices[9].position = sf::Vector2f(pos.x + width_per * 2, pos.y);
	vertices[10].position = sf::Vector2f(pos.x + width_per * 3, pos.y);
	vertices[11].position = sf::Vector2f(pos.x + width_per * 3, pos.y + height);
	vertices[8].color = sf::Color::Green;
	vertices[9].color = sf::Color::Green;
	vertices[10].color = sf::Color::Cyan;
	vertices[11].color = sf::Color::Cyan;

	vertices[12].position = sf::Vector2f(pos.x + width_per * 3, pos.y + height);
	vertices[13].position = sf::Vector2f(pos.x + width_per * 3, pos.y);
	vertices[14].position = sf::Vector2f(pos.x + width_per * 4, pos.y);
	vertices[15].position = sf::Vector2f(pos.x + width_per * 4, pos.y + height);
	vertices[12].color = sf::Color::Cyan;
	vertices[13].color = sf::Color::Cyan;
	vertices[14].color = sf::Color::Blue;
	vertices[15].color = sf::Color::Blue;

	vertices[16].position = sf::Vector2f(pos.x + width_per * 4, pos.y + height);
	vertices[17].position = sf::Vector2f(pos.x + width_per * 4, pos.y);
	vertices[18].position = sf::Vector2f(pos.x + width_per * 5, pos.y);
	vertices[19].position = sf::Vector2f(pos.x + width_per * 5, pos.y + height);
	vertices[16].color = sf::Color::Blue;
	vertices[17].color = sf::Color::Blue;
	vertices[18].color = sf::Color::Magenta;
	vertices[19].color = sf::Color::Magenta;

	vertices[20].position = sf::Vector2f(pos.x + width_per * 5, pos.y + height);
	vertices[21].position = sf::Vector2f(pos.x + width_per * 5, pos.y);
	vertices[22].position = sf::Vector2f(pos.x + width_per * 6, pos.y);
	vertices[23].position = sf::Vector2f(pos.x + width_per * 6, pos.y + height);
	vertices[20].color = sf::Color::Magenta;
	vertices[21].color = sf::Color::Magenta;
	vertices[22].color = sf::Color::Red;
	vertices[23].color = sf::Color::Red;
}