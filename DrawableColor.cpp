#include "DrawableColor.h"

DrawableColor::DrawableColor(const sf::Vector2f position, const setting::Type type, ColorSetting* setting, Whiteout& whiteout) : DrawableSetting(position, type, whiteout), setting(setting) {}

void DrawableColor::draw(float& height, sf::Vector2f outline_r_w) {
	sf::VertexArray vertices(sf::PrimitiveType::Quads, 24);
	create_hue_vertecies(vertices);

	whiteout.window.draw(vertices);

	height += 300;
}

bool DrawableColor::on_event(const Key key, const mdl::MODULE_CATEGORY current) {
	return false;
}

void DrawableColor::create_hue_vertecies(sf::VertexArray& vertices) {
	vertices[0].position = sf::Vector2f(pos.x, pos.y);
	vertices[1].position = sf::Vector2f(pos.x + 15, pos.y);
	vertices[2].position = sf::Vector2f(pos.x + 15, pos.y + 25);
	vertices[3].position = sf::Vector2f(pos.x, pos.y + 25);
	vertices[0].color = sf::Color::Red;
	vertices[1].color = sf::Color::Red;
	vertices[2].color = sf::Color::Yellow;
	vertices[3].color = sf::Color::Yellow;

	vertices[4].position = sf::Vector2f(pos.x, pos.y + 25);
	vertices[5].position = sf::Vector2f(pos.x + 15, pos.y + 25);
	vertices[6].position = sf::Vector2f(pos.x + 15, pos.y + 50);
	vertices[7].position = sf::Vector2f(pos.x, pos.y + 50);
	vertices[4].color = sf::Color::Yellow;
	vertices[5].color = sf::Color::Yellow;
	vertices[6].color = sf::Color::Green;
	vertices[7].color = sf::Color::Green;

	vertices[8].position = sf::Vector2f(pos.x, pos.y + 50);
	vertices[9].position = sf::Vector2f(pos.x + 15, pos.y + 50);
	vertices[10].position = sf::Vector2f(pos.x + 15, pos.y + 75);
	vertices[11].position = sf::Vector2f(pos.x, pos.y + 75);
	vertices[8].color = sf::Color::Green;
	vertices[9].color = sf::Color::Green;
	vertices[10].color = sf::Color::Cyan;
	vertices[11].color = sf::Color::Cyan;

	vertices[12].position = sf::Vector2f(pos.x, pos.y + 75);
	vertices[13].position = sf::Vector2f(pos.x + 15, pos.y + 75);
	vertices[14].position = sf::Vector2f(pos.x + 15, pos.y + 100);
	vertices[15].position = sf::Vector2f(pos.x, pos.y + 100);
	vertices[12].color = sf::Color::Cyan;
	vertices[13].color = sf::Color::Cyan;
	vertices[14].color = sf::Color::Blue;
	vertices[15].color = sf::Color::Blue;

	vertices[16].position = sf::Vector2f(pos.x, pos.y + 100);
	vertices[17].position = sf::Vector2f(pos.x + 15, pos.y + 100);
	vertices[18].position = sf::Vector2f(pos.x + 15, pos.y + 125);
	vertices[19].position = sf::Vector2f(pos.x, pos.y + 125);
	vertices[16].color = sf::Color::Blue;
	vertices[17].color = sf::Color::Blue;
	vertices[18].color = sf::Color::Magenta;
	vertices[19].color = sf::Color::Magenta;

	vertices[20].position = sf::Vector2f(pos.x, pos.y + 125);
	vertices[21].position = sf::Vector2f(pos.x + 15, pos.y + 125);
	vertices[22].position = sf::Vector2f(pos.x + 15, pos.y + 150);
	vertices[23].position = sf::Vector2f(pos.x, pos.y + 150);
	vertices[20].color = sf::Color::Magenta;
	vertices[21].color = sf::Color::Magenta;
	vertices[22].color = sf::Color::Red;
	vertices[23].color = sf::Color::Red;
}