#pragma once
#include <map>
#include "JavaClass.h"

namespace clr {
	// Loads classes from JSON
	void createClassesFromJSON(const char* path, std::map<const char*, JavaClass>);
}