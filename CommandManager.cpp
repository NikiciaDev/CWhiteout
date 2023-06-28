#include "CommandManager.h"

namespace CommandManager {
	void init_commands() {

	}

	void unload_commands() {
		std::for_each(commands.begin(), commands.end(), [](const std::pair<const std::string, Command*>& pair) {
			delete pair.second;
			});
		commands.clear();
	}

}