#pragma once
#include <map>
#include <jni.h>
#include "Module.h"

JavaVM* jvm_ptr{ nullptr };
JNIEnv* jenv_ptr{ nullptr };
std::map<const std::string, const std::unique_ptr<Module>> modules;

void init_variables();