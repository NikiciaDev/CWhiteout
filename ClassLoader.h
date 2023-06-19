#pragma once
#include <map>
#include "LdrfUtil.h"
#include "JavaClass.h"

namespace clr {
	void create_classes_from_ldrf(const char* path, std::map<const char*, JavaClass*>& map);
}