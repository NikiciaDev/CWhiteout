#include "ClassLoader.h"

namespace clr {
	void create_classes_from_ldrf(const char* path, std::map<const char*, JavaClass>& map) {
		lul::load_classes_from_ldrf(path, map);
	}
}