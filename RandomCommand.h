#pragma once
#include "Command.h"
#include "Random.h"

class RandomCommand final : public Command {
private:
	Random rndm;

public:
	RandomCommand(const std::string name);

	std::string on_call(const std::string args) override;
};