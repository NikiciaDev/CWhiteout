#include "ShellCommand.h"

ShellCommand::ShellCommand(const std::string name) : Command(name) {}

std::string ShellCommand::on_call(const std::string args) { // Does not grag std::err.
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(args.c_str(), "r"), _pclose);
    if (!pipe) return "popen() failed!";

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}