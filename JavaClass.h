#pragma once
#include <map>
#include "jni.h"

class JavaClass {
public:
	const char* name;
	jclass jclass;
	std::map<const char*, jmethodID> jmethods;
	std::map<const char*, jfieldID> jfields;

	JavaClass(const char* name);

	~JavaClass();

	void init();
};