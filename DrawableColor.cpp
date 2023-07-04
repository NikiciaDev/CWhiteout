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

	sf::Vector2 _pos(pos.x + outline_r_w.x - 20 - 10 - rec_w + 1, pos.y + font::height(n_t) + 15);
	if (extened) {
		sf::VertexArray vertices(sf::PrimitiveType::Quads, 24);
		create_hue_vertecies(vertices, _pos);
		bar_bounds.setPosition(_pos);
		bar_bounds.setSize(sf::Vector2f(30, 180));
		whiteout.window.draw(vertices);

		if (dragging_bar) {
			if (bar_bounds.getGlobalBounds().contains(liu::get_cursor_pos(true))) {
				hue_bar_y = liu::get_cursor_pos(true).y;
				sf::Texture texture;
				texture.create(whiteout.window.getSize().x, whiteout.window.getSize().y);
				texture.update(whiteout.window);
				sf::Image img = texture.copyToImage();
				setting->sv(img.getPixel(_pos.x + 5, hue_bar_y));
			} else {
				dragging_bar = false;
			}
		}

		if (hue_bar_y != 0) {
			render::rect_outline(whiteout.window, sf::Vector2f(_pos.x - 2, hue_bar_y - 2), sf::Vector2f(rec_w + 3, 4), Whiteout::text_color, 2.f);
		}

		height += 200;
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

void DrawableColor::create_hue_vertecies(sf::VertexArray& vertices, const sf::Vector2f pos) {
	vertices[0].position = sf::Vector2f(pos.x, pos.y);
	vertices[1].position = sf::Vector2f(pos.x + 15, pos.y);
	vertices[2].position = sf::Vector2f(pos.x + 15, pos.y + 30);
	vertices[3].position = sf::Vector2f(pos.x, pos.y + 30);
	vertices[0].color = sf::Color::Red;
	vertices[1].color = sf::Color::Red;
	vertices[2].color = sf::Color::Yellow;
	vertices[3].color = sf::Color::Yellow;

	vertices[4].position = sf::Vector2f(pos.x, pos.y + 30);
	vertices[5].position = sf::Vector2f(pos.x + 15, pos.y + 30);
	vertices[6].position = sf::Vector2f(pos.x + 15, pos.y + 60);
	vertices[7].position = sf::Vector2f(pos.x, pos.y + 60);
	vertices[4].color = sf::Color::Yellow;
	vertices[5].color = sf::Color::Yellow;
	vertices[6].color = sf::Color::Green;
	vertices[7].color = sf::Color::Green;

	vertices[8].position = sf::Vector2f(pos.x, pos.y + 60);
	vertices[9].position = sf::Vector2f(pos.x + 15, pos.y + 60);
	vertices[10].position = sf::Vector2f(pos.x + 15, pos.y + 90);
	vertices[11].position = sf::Vector2f(pos.x, pos.y + 90);
	vertices[8].color = sf::Color::Green;
	vertices[9].color = sf::Color::Green;
	vertices[10].color = sf::Color::Cyan;
	vertices[11].color = sf::Color::Cyan;

	vertices[12].position = sf::Vector2f(pos.x, pos.y + 90);
	vertices[13].position = sf::Vector2f(pos.x + 15, pos.y + 90);
	vertices[14].position = sf::Vector2f(pos.x + 15, pos.y + 120);
	vertices[15].position = sf::Vector2f(pos.x, pos.y + 120);
	vertices[12].color = sf::Color::Cyan;
	vertices[13].color = sf::Color::Cyan;
	vertices[14].color = sf::Color::Blue;
	vertices[15].color = sf::Color::Blue;

	vertices[16].position = sf::Vector2f(pos.x, pos.y + 120);
	vertices[17].position = sf::Vector2f(pos.x + 15, pos.y + 120);
	vertices[18].position = sf::Vector2f(pos.x + 15, pos.y + 150);
	vertices[19].position = sf::Vector2f(pos.x, pos.y + 150);
	vertices[16].color = sf::Color::Blue;
	vertices[17].color = sf::Color::Blue;
	vertices[18].color = sf::Color::Magenta;
	vertices[19].color = sf::Color::Magenta;

	vertices[20].position = sf::Vector2f(pos.x, pos.y + 150);
	vertices[21].position = sf::Vector2f(pos.x + 15, pos.y + 150);
	vertices[22].position = sf::Vector2f(pos.x + 15, pos.y + 180);
	vertices[23].position = sf::Vector2f(pos.x, pos.y + 180);
	vertices[20].color = sf::Color::Magenta;
	vertices[21].color = sf::Color::Magenta;
	vertices[22].color = sf::Color::Red;
	vertices[23].color = sf::Color::Red;
}