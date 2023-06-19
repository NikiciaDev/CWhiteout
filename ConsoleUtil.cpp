#include "ConsoleUtil.h"

std::string get_print_str(const char* string, bool err, bool warn) {
	std::string sstring(!err && !warn ? "[Whiteout] " : err ? "[Error] " : "[Warning] ");
	sstring += string;
	return sstring;
}

void print(const char* string) {
	printf_s(get_print_str(string, false, false).c_str());
}

void print(const char* string, const char* format) {
	printf_s(get_print_str(string, false, false).c_str(), format);
}

void print_wrn(const char* string) {
	printf_s(get_print_str(string, false, true).c_str());
}

void print_wrn(const char* string, const char* format) {
	printf_s(get_print_str(string, false, true).c_str(), format);
}

void print_err(const char* string) {
	printf_s(get_print_str(string, true, false).c_str());
}

void print_err(const char* string, const char* format) {
	printf_s(get_print_str(string, true, false).c_str(), format);
}