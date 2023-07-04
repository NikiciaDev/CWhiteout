#include "DrawableColor.h"

DrawableColor::DrawableColor(const sf::Vector2f position, const setting::Type type, ColorSetting* setting, Whiteout& whiteout) : DrawableSetting(position, type, whiteout), setting(setting) {}

void DrawableColor::draw(float& height, sf::Vector2f outline_r_w) {
	if (!setting->dependency()) return;
	this->outline_r_w = outline_r_w;
	sf::Text n_t = font::text(setting->name, pos);
	font::render(whiteout.window, n_t);
	render::rect(whiteout.window, sf::Vector2f(pos.x + outline_r_w.x - 20 - 10 - font::height(), pos.y + 2.5f), sf::Vector2f(font::height(), font::height()), setting->gv<sf::Color>());

	sf::Vector2 _pos(pos.x + font::width(n_t), pos.y + font::height(n_t));
	if (extened) {
		sf::VertexArray vertices(sf::PrimitiveType::Quads, 24);
		create_hue_vertecies(vertices, _pos);
		whiteout.window.draw(vertices);

		height += 300;
	}

	height += font::height();
}

bool DrawableColor::on_event(const Key key, const mdl::MODULE_CATEGORY current) {
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