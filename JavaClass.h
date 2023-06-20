#pragma once
#include <map>
#include <string>
#include <algorithm>
#include <jni.h>

extern JavaVM* jvm_ptr;
extern JNIEnv* jenv_ptr;

class JavaClass final {
public:
	std::string c_name;
	std::string name;
	jclass jclass{ NULL };
	jobject instance{ NULL };
	jmethodID constructor_id{ NULL };
	std::map<const std::string, jmethodID*> jmethods;
	std::map<const std::string, jfieldID*> jfields;

	explicit JavaClass();

	explicit JavaClass(const std::string, const std::string);

	~JavaClass();

	jobject new_instance();
};