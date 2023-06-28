#pragma once
#include <string>

class Command {
public:
	std::string alias { "" };
	std::string name { "" };


	virtual void on_call();
};