#pragma once
#include <map>
#include <jni.h>
#include "Whiteout.h"
#include "Module.h"

namespace ModuleManager {
	std::map<const std::string, Module*> modules;
}

namespace frr {
	sf::Font rmb, rmm, rmr, rmt;
}

Whiteout* whiteout;
JavaVM* jvm_ptr{ nullptr };
JNIEnv* jenv_ptr{ nullptr };

void init_variables(const std::string font_path);