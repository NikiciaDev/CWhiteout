#include "RenderUtil.h"

namespace render {
	void rect_outline(sf::RenderWindow& window, const sf::Vector2f position, const sf::Vector2f size, const sf::Color color, const float thickness) {
		sf::RectangleShape rectangle;
		rectangle.setPosition(position);
		rectangle.setSize(size);
		rectangle.setOutlineColor(color);
		rectangle.setOutlineThickness(thickness);
		rectangle.setFillColor(sf::Color::Transparent);
		window.draw(rectangle);
	}

	void circle_outline(sf::RenderWindow& window, const sf::Vector2f position, const sf::Vector2f radius_points, const sf::Color color, const float thickness) {
		sf::CircleShape circle;
		circle.setPosition(position);
		circle.setRadius(radius_points.x);
		circle.setPointCount(radius_points.y);
		circle.setOutlineColor(color);
		circle.setOutlineThickness(thickness);
		circle.setFillColor(sf::Color::Transparent);
		window.draw(circle);
	}

	void rect_outline_cutout(sf::RenderWindow& window, const sf::Vector2f position, const sf::Vector2f size, const sf::Color color, const float thickness, const float cutout_position, const float cutout_length) {
		// Draw the top line.
		sf::VertexArray lines(sf::LinesStrip, 2);
		lines[0] = sf::Vertex(position, color);
		lines[1] = sf::Vertex({ position.x + cutout_position, position.y }, color);
		window.draw(lines);
		lines[0] = sf::Vertex({ position.x + cutout_position + cutout_length, position.y }, color);
		lines[1] = sf::Vertex({ position.x + size.x, position.y }, color);
		window.draw(lines);

		// Draw the bottom line.
		lines[0] = sf::Vertex({ position.x, position.y + size.y }, color);
		lines[1] = sf::Vertex({ position.x + size.x, position.y + size.y }, color);
		window.draw(lines);

		// Draw the left and right lines of the cutout.
		lines[0] = sf::Vertex(position, color);
		lines[1] = sf::Vertex({ position.x, position.y + size.y }, color);
		window.draw(lines);
		lines[0] = sf::Vertex({ position.x + size.x, position.y }, color);
		lines[1] = sf::Vertex({ position.x + size.x, position.y + size.y }, color);
		window.draw(lines);
	}
}