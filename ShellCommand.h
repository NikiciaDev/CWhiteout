#pragma once
#define NOMINMAX

#include <Windows.h>
#include <cstdio>
#include <memory>
#include <string>
#include <array>
#include "Command.h"

class ShellCommand final : public Command {
public:
	ShellCommand(const std::string name);

	std::string on_call(const std::string args) override;
};