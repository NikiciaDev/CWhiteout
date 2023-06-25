#include "Module.h"

Module::Module(const std::string name) : name(name) { }

void Module::on_call() {
	print_wrn("Base module on_call called. This should not happen!");
}