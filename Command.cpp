#include "Command.h"

Command::Command(const std::string name) : name(name) { }

std::string Command::on_call(const std::string args) { return "Error"; }