#include "LdrfUtil.h"

namespace lul {
	void load_classes_from_ldrf(std::ifstream& file, std::map<const std::string, JavaClass*>& map) {
		bool in_block{ false };
		std::string current_class{ "" };
		for (std::string line; std::getline(file, line);) {
			if (!in_block && line == "{") {
				in_block = true;
				continue;
			}
			if (!in_block) continue;

			if (line.find("class:") != std::string::npos) {
				current_class = get_class_name(line);
				JavaClass* java_class = new JavaClass(get_class_c_name(line), current_class);
				set_instance(line, *java_class, map);
				map.insert(std::make_pair(current_class, java_class));
				continue;
			}

			if (line.find("fields:") != std::string::npos) {
				extract_mof_from_class(line, *map[current_class], map[current_class]->jmethods, map[current_class]->jfields, false);
				continue;
			}

			if (line.find("methods:") != std::string::npos) {
				extract_mof_from_class(line, *map[current_class], map[current_class]->jmethods, map[current_class]->jfields, true);
				continue;
			}
		}
	}

	void extract_mof_from_class(const std::string line, JavaClass& clazz, std::map<const std::string, jmethodID*>& map,
		std::map<const std::string, jfieldID*>& fmap, bool methods) {

		bool in{ false }, completed{ false };
		bool is_static{ false };
		unsigned short begin{ 0 }, end{ 0 };
		std::string name{ "" }, c_name{ "" }, signature{""};
		for (unsigned short s = 0; s < line.size(); s++) {
			const char c = line[s];
			if (c == '<') {
				in = true;
				completed = false;
				begin = s;
				continue;
			}
			if (c == '>') in = false;

			if (in && !completed) {
				bool is_static = line[begin + 1] == 't';
				unsigned short first_comma = line.find_first_of(',', begin);
				unsigned short second_comma = line.find_first_of(',', first_comma + 1);
				unsigned short third_comma = line.find_first_of(',', second_comma + 1);
				end = line.find_first_of('>', third_comma + 1);

				c_name = line.substr(first_comma + 2, second_comma - first_comma - 3);
				name = line.substr(second_comma + 2, third_comma - second_comma - 3);
				signature = line.substr(third_comma + 1, end - third_comma - 1);

				if (methods) {
					jmethodID* method;
					if (is_static) {
						method = new jmethodID{ jenv_ptr->GetStaticMethodID(clazz.jclass, c_name.c_str(), signature.c_str()) };
					} else {
						method = new jmethodID{ jenv_ptr->GetMethodID(clazz.jclass, c_name.c_str(), signature.c_str()) };
					}
					map.insert(std::make_pair(name, method));
				} else {
					jfieldID* field;
					if (is_static) {
						field = new jfieldID{ jenv_ptr->GetStaticFieldID(clazz.jclass, c_name.c_str(), signature.c_str()) };
					} else {
						field = new jfieldID{ jenv_ptr->GetFieldID(clazz.jclass, c_name.c_str(), signature.c_str()) };
					}
					fmap.insert(std::make_pair(name, field));
				}

				completed = true;
				s = end;
			}
		}
	}

	void set_instance(const std::string line, JavaClass& java_class, std::map<const std::string, JavaClass*>& map) {
		if (line.find("?") != std::string::npos) {
			java_class.instance = NULL;
			print_wrn("Loading class without instance. Non static methods can not be called without creating your own instance!\n");
			return;
		}
		unsigned short ff0 = line.find("<") + 1, ff1 = line.find_first_of(","), ff2 = line.find_first_of(',', ff1 + 1), ff3 = line.find_last_of(",");
		if (ff0 + 1 == ff1) return;

		std::string name = line.substr(ff0 + 1, ff1 - ff0 - 1 - 1), signature = line.substr(ff1 + 1, ff2 - ff1 - 1);
		std::string class_to_find_in = line.substr(ff2 + 1, ff3 - ff2 - 1);
		bool is_static = (line[ff3 + 1] == 't');

		jfieldID id;
		jclass c = (signature == class_to_find_in) ? java_class.jclass : map.find(class_to_find_in)->second->jclass;
		if (is_static) {
			id = jenv_ptr->GetStaticFieldID(c, name.c_str(), signature.c_str());
			java_class.instance = jenv_ptr->GetStaticObjectField(c, id);
		} else {
			print_wrn("Non static class instances can get freed and cause errors!\n");
			id = jenv_ptr->GetFieldID(c, name.c_str(), signature.c_str());
			java_class.instance = jenv_ptr->GetObjectField(map.find(class_to_find_in)->second->instance, id);
		}
		if (id == NULL || java_class.instance == NULL) {
			print_wrn("Could not find instance field for class.\n");
			return;
		}
		
	}

	std::string get_class_c_name(const std::string line) {
		short start{ -1 }, end{ -1 };
		for (unsigned short s = 0; s < line.size(); s++) {
			if (line[s] == '"') {
				if (start == -1) start = s;
				else if (end == -1) end = s;
			}
			if (start != -1 && end != -1) break;
		}
		return line.substr(start + 1, end - start - 1);
	}

	std::string get_class_name(const std::string line) {
		short start{ -1 }, end{ -1 }, count{ 0 };
		for (unsigned short s = 0; s < line.size(); s++) {
			if (line[s] == '"') {
				if (count > 1) {
					if (start == -1) start = s;
					else if (end == -1) end = s;
				}
				count++;
			}
		}
		return line.substr(start + 1, end - start - 1);
	}
}