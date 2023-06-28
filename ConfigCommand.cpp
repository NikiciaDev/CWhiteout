#include "ConfigCommand.h"

ConfigCommand::ConfigCommand(const std::string name) : Command(name) { }

std::string ConfigCommand::on_call(const std::string args) {
	return std::string("Not implemented yet :(!");
}
