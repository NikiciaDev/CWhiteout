#pragma once
#include <map>
#include <algorithm>
#include "Command.h"
#include "ConfigCommand.h"

namespace CommandManager {
	extern std::map<const std::string, Command*> commands;

	// Same as modulemanager but for commands.
	void init_commands();

	// Same as modulemanager but for commands.
	void unload_commands();
}