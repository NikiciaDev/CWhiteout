#include "Command.h"

Command::Command(const std::string alias, const std::string name) : alias(alias), name(name) { }

std::string Command::on_call(const std::string args) { return "Error"; }