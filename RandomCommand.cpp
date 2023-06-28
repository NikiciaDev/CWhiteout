#include "RandomCommand.h"

RandomCommand::RandomCommand(const std::string name) : Command(name) { }

std::string RandomCommand::on_call(const std::string args) {
	unsigned int numbers;
	try {
		numbers = std::stoi(args);

		std::string random_numbers("Randomly generated numbers: { ");
		for (unsigned int i = 0; i < numbers; i++) {
			random_numbers += std::to_string(rul::rndm_floatingpoint_ir<float>(-1, 1));
			if (i != numbers - 1) random_numbers += ",";
			random_numbers += " ";
		}

		return random_numbers + "}";
	} catch (const std::invalid_argument e) {
		return "Invalid arguent!";
	} catch (const std::out_of_range e) {
		return "Arguent out of range!";
	}
}
