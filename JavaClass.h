#pragma once
#include <vector>
#include "jni.h"

class JavaClass {
public:
	const char* name;
	jclass jclass;
	std::vector<jmethodID> jmethods;
	std::vector<jfieldID> jfields;

	JavaClass(const char* name);

	~JavaClass();

	void init();
};