#pragma once
#include "Command.h"

class ConfigCommand final : public Command {
public:
	ConfigCommand(const std::string name);
	
	std::string on_call(const std::string args) override;
};