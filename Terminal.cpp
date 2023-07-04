#include "Terminal.h"

Terminal::Terminal(Whiteout& whiteout, CategorySelectionButton& csb) : whiteout(whiteout), csb(csb) { }

Terminal::~Terminal() {
	clean();
}

void Terminal::draw() {
	for (SentCommand& c : sent_commands) {
		font::render(whiteout.window, c.prompt, c.input_pos, font::mm, 16);
		font::render(whiteout.window, c.response, sf::Vector2f(c.input_pos.x, c.input_pos.y + font::height(c.prompt, font::mm, 16) + 5), font::mm, 16);
	}

	std::string s(whiteout.name); s += "@"; s += Clock<std::chrono::seconds>::get_time(); s += ">";	s += current_in;
	unsigned short last_c = (unsigned short) s[s.size() - 2];
	if (clock.has_time_elapsed(std::chrono::milliseconds(500))) {
		display_a_c = !display_a_c;
		clock.reset();
	}
	if (display_a_c) s += "|";
	font::render(whiteout.window, s, input_pos, font::mm, 16, sf::Text::Bold);
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
				std::string s(SentCommand::get_pre_string(whiteout)); s += current_in;
				
				std::string response{ "Error" };
				unsigned short sp = current_in.find_first_of(" ");
				if (current_in == "CLS") {
					clean();
					input_pos.x = 35; input_pos.y = 35;
					whiteout.view.reset(sf::FloatRect(0, 0, whiteout.window.getSize().x, whiteout.window.getSize().y));
					whiteout.window.setView(whiteout.view);
					goto end2;
				} else if (current_in.substr(0, 4) == "GOTO") {
					if (current_in.size() <= 5) {
						sent_commands.push_back(SentCommand(input_pos, s, "Failed to identify window!"));
					} else {
						std::string cat = current_in.substr(sp + 1, current_in.size() - 1);
						auto cat_e = std::find(mdcn_a.begin(), mdcn_a.end(), cat);
						if (cat_e != mdcn_a.end()) {
							csb.current = (mdl::MODULE_CATEGORY) (cat_e - mdcn_a.begin());
							sent_commands.push_back(SentCommand(input_pos, s, "Successfully changed windows."));
						} else {
							sent_commands.push_back(SentCommand(input_pos, s, "Failed to identify window!"));
						}
					}
					goto end;
				} else if (current_in.substr(0, 5) == "SCALE") {
					try {
						std::string sub = current_in.substr(sp + 1, current_in.size() - 1);
						if (sub == "RESET") {
							whiteout.window.setSize(sf::Vector2u(1000, 600));
							sent_commands.push_back(SentCommand(input_pos, s, "Successfully reset window scale."));
							goto end;
						}
						float f = std::stof(sub);
						whiteout.window.setSize(sf::Vector2u(f * whiteout.window.getSize().x, f * whiteout.window.getSize().y));
						sent_commands.push_back(SentCommand(input_pos, s, "Successfully scaled window."));
						goto end;
					} catch (const std::invalid_argument e) {
						sent_commands.push_back(SentCommand(input_pos, s, "Invalid Argument"));
						goto end;
					} catch (const std::out_of_range e) {
						sent_commands.push_back(SentCommand(input_pos, s, "Argument out of range!"));
						goto end;
					}
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
				input_pos.y += font::height(response, font::mm, 16) + font::height(s, font::mm, 16) + 15;
				if (sent_commands.size() >= 30) sent_commands.erase(sent_commands.begin());
			end2:
				current_in.clear();
				return;
			}
			current_in += (char) key.keycode;
		}
	}
}

void Terminal::clean() {
	sent_commands.clear();
}
