#pragma once
#include <map>
#include <fstream>
#include <string>
#include "ConsoleUtil.h"
#include "JavaClass.h"

extern JNIEnv* jenv_ptr;

namespace lul {
	void load_classes_from_ldrf(std::ifstream& file, std::map<const char*, JavaClass*>& map);

	void extract_methods_from_class(const std::string line, std::map<const char*, jmethodID*>& map);

	void extract_fields_from_class(const std::string line, std::map<const char*, jfieldID*>& map);

	void set_instance(const std::string line, JavaClass& java_class);

	std::string get_class_c_name(const std::string line);

	std::string get_class_name(const std::string line);
}