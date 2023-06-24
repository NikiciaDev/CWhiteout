#pragma once
#include <map>
#include "ConsoleUtil.h"
#include "LdrfUtil.h"
#include "JavaClass.h"

namespace clr {
	void create_classes_from_ldrf(const std::wstring path, std::map<const std::string, JavaClass*>& map);
}