#pragma once
#include <map>
#include <jni.h>
#include "Module.h"

namespace ModuleManager {
	std::map<const std::string, const std::unique_ptr<Module>> modules;
}

JavaVM* jvm_ptr{ nullptr };
JNIEnv* jenv_ptr{ nullptr };

void init_variables();