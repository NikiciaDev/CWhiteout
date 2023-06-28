#include "Terminal.h"

Terminal::Terminal(Whiteout& whiteout) : whiteout(whiteout) { }

void Terminal::draw() {
	for (SentCommand& c : sent_commands) { // The renders break it idk why.
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
	font::render(whiteout.window, s, input_pos, font::mm, 14, sf::Text::Italic);
}

void Terminal::on_key_press(const Key key) {
	if (key.keycode < 255) {
		if (key.keycode == 8) {
			if (current_in.size() <= 0) return;
			current_in.erase(current_in.size() - 1);
			return;
		} else {
			if (key.keycode == 13) { // Enter.
				if (current_in.empty()) return;
				std::string s(whiteout.name); s += "@"; s += Clock<std::chrono::seconds>::get_time(); s += ">";	s += current_in;
				
				std::string response{ "Error" };
				unsigned short sp = current_in.find_first_of(" ");
				if (current_in == "CLS") {
					clean();
					input_pos.x = 35; input_pos.y = 35;
					goto end2;
				}

				if (CommandManager::commands.find(current_in) != CommandManager::commands.end()) {
					if (sp == std::string::npos) {
						sent_commands.push_back(SentCommand(input_pos, s, "Command not found!"));
						goto end;
					}
					response = CommandManager::commands.find(current_in)->second->on_call("");
				} else {					
					if (CommandManager::commands.find(current_in.substr(0, sp)) != CommandManager::commands.end()) {
						response = CommandManager::commands.find(current_in.substr(0, sp))->second->on_call(current_in.substr(sp + 1, current_in.size() - 1));
					} else {
						sent_commands.push_back(SentCommand(input_pos, s, "Command not found!"));
						goto end;
					}
				}
				
				sent_commands.push_back(SentCommand(input_pos, s, response));
			end:
				input_pos.y += font::height() * 2 + 10;
			end2:
				current_in.clear();
				if (sent_commands.size() >= 50) sent_commands.erase(sent_commands.begin());
				return;
			}
			current_in += (char) key.keycode;
		}
	}
}

void Terminal::clean() {
	sent_commands.clear();
	sent_commands.shrink_to_fit();
}
