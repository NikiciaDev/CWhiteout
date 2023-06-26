#pragma once
#include <map>
#include <fstream>
#include <string>
#include "ConsoleUtil.h"
#include "JavaClass.h"

extern JNIEnv* jenv_ptr;

// Arrays are fields so they would be represented like this for example: <false,"c_name","name",[B;>. The "[" signals that the field is an array.
// How to use those: https://stackoverflow.com/questions/1086596/how-to-access-arrays-within-an-object-with-jni

namespace lul {
	void load_classes_from_ldrf(std::ifstream& file, std::map<const std::string, JavaClass*>& map);

	void extract_mof_from_class(const std::string line, JavaClass& clazz, std::map<const std::string, jmethodID*>& map, std::map<const std::string, jfieldID*>& fmap, bool methods);

	void set_instance(const std::string line, JavaClass& java_class);

	unsigned short find_next_char(const std::string& line, char char_to_find, unsigned short start);

	std::string get_class_c_name(const std::string line);

	std::string get_class_name(const std::string line);
}