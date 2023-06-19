#include "LdrfUtil.h"

namespace lfe {
	void load_classes_from_ldrf(const char* path, std::map<const char*, JavaClass>& map) {
		std::ifstream file(path);
		if (!file.is_open()) {
			throw std::exception("Could not open ldrf file!");
		}

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
				map.insert(std::make_pair(current_class.c_str(), JavaClass(get_class_c_name(line).c_str(), current_class.c_str())));
				continue;
			}

			if (line.find("fields:") != std::string::npos) {
				extract_fields_from_class(line, map[current_class.c_str()].jfields);
				continue;
			}

			if (line.find("methods:") != std::string::npos) {
				extract_methods_from_class(line, map[current_class.c_str()].jmethods);
				continue;
			}
		}
	}

	void extract_methods_from_class(const std::string line, std::map<const char*, jmethodID>& map) {

	}

	void extract_fields_from_class(const std::string line, std::map<const char*, jfieldID>& map) {
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
		return line.substr(start, end);
	}

	std::string get_class_name(const std::string line) {
		short start{ -1 }, end{ -1 }, count{ 0 };
		for (unsigned short s = 0; s < line.size(); s++) {
			if (line[s] == '"') {
				if (count >= 1) {
					if (start == -1) start = s;
					else if (end == -1) end = s;
				}
				count++;
			}
		}
		return line.substr(start, end);
	}
}