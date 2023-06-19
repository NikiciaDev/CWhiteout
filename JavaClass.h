#pragma once
#include <map>
#include <jni.h>

extern JavaVM* jvm_ptr;
extern JNIEnv* jenv_ptr;

class JavaClass {
public:
	const char* c_name;
	const char* name;
	jclass jclass;
	std::map<const char*, jmethodID> jmethods;
	std::map<const char*, jfieldID> jfields;

	explicit JavaClass();

	explicit JavaClass(const char* c_name, const char* name);

	~JavaClass();

	void init();
};