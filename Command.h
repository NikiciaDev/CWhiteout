#pragma once
#include <string>

class Command {
public:
	std::string alias{ "" };
	std::string name { "" };

	Command();

	virtual void on_call();
};