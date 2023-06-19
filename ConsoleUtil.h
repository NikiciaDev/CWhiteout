#pragma once
#include <cstdio>
#include <string>

std::string get_print_str(const char* string, bool err, bool warn);

void print(const char* string);

void print(const char* string, const char* format);

void print_wrn(const char* string);

void print_wrn(const char* string, const char* format);

void print_err(const char* string);

void print_err(const char* string, const char* format);