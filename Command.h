#pragma once
#include <string>

class Command {
public:
	const std::string name { "" };

	Command(const std::string name);

	virtual std::string on_call(const std::string args);
};