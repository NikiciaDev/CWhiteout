#include "SentCommand.h"

SentCommand::SentCommand(sf::Vector2f input_pos, std::string prompt, std::string response) : input_pos(input_pos), prompt(prompt), response(response) { }

std::string SentCommand::get_pre_string(const Whiteout& whiteout) {
    std::string s(whiteout.name); s += "@"; s += Clock<std::chrono::seconds>::get_time(); s += ">";
    return s;
}
