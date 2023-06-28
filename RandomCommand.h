#pragma once
#include "Command.h"
#include "RandomUtil.h"

class RandomCommand final : public Command {
public:
	RandomCommand(const std::string name);

	std::string on_call(const std::string args) override;
};