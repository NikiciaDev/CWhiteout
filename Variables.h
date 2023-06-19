#pragma once
#include <jni.h>

JavaVM* jvm_ptr{ nullptr };
JNIEnv* jenv_ptr{ nullptr };

void init_variables();