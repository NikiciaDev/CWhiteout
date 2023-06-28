#include "Terminal.h"

Terminal::Terminal(Whiteout& whiteout) : whiteout(whiteout) { }

void Terminal::draw() {
	for (SentCommand& c : sent_commands) {
		font::render(whiteout.window, c.prompt, c.input_pos, font::mm, 14);
		font::render(whiteout.window, c.response, sf::Vector2f(c.input_pos.x, c.input_pos.y + font::height() + 5), font::mm, 14);
	}

	std::string s(whiteout.name); s += "@"; s += Clock<std::chrono::seconds>::get_time(); s += ">";	s += current_in;
	unsigned short last_c = (unsigned short) s[s.size() - 2];
	if (clock.has_time_elapsed(std::chrono::milliseconds(500))) {
		display_a_c = !display_a_c;
		clock.reset();
	}
	if (display_a_c) s += "|";
	font::render(whiteout.window, s, input_pos, font::mm, 14, sf::Text::Bold | sf::Text::Italic);
}

void Terminal::on_key_press(const Key key) {
	if (key.keycode < 255) {
		if (key.keycode == 8) {
			if (current_in.size() <= 0) return;
			current_in.erase(current_in.size() - 1);
			return;
		} else {
			if (key.keycode == 13) { // Enter.
				std::string s(whiteout.name); s += "@"; s += Clock<std::chrono::seconds>::get_time(); s += ">";	s += current_in;
				sent_commands.push_back(SentCommand(input_pos, s, "Respnse"));
				current_in.clear();
				input_pos.y += font::height() * 2 + 10;
				if (sent_commands.size() >= 50) sent_commands.erase(sent_commands.begin());
				return;
			}
			current_in += (char) key.keycode;
		}
	}
}