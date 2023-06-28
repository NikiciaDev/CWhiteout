#pragma once
#define NOMINMAX

#include <Windows.h>
#include <cstdio>
#include <memory>
#include <string>
#include <array>
#include "Command.h"

class CMDCommand final : public Command {
public:
	CMDCommand(const std::string name);

	std::string on_call(const std::string args) override;
};