#include "CommandManager.h"

namespace CommandManager {
	void init_commands() {
		ConfigCommand* config_command = new ConfigCommand("CONFIG");
		commands.insert(std::make_pair(config_command->name, config_command));
	}

	void unload_commands() {
		std::for_each(commands.begin(), commands.end(), [](const std::pair<const std::string, Command*>& pair) {
			delete pair.second;
			});
		commands.clear();
	}

}