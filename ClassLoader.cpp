#include "ClassLoader.h"

namespace clr {
	void create_classes_from_ldrf(const char* path, std::map<const std::string, JavaClass*>& map) {
		std::ifstream file(path);
		if (!file.is_open()) {
			print_err("Could not open ldrf file!");
			throw std::exception("Could not open ldrf file!");
		}
		lul::load_classes_from_ldrf(file, map);
	}
}