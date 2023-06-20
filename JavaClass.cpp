#include "JavaClass.h"

JavaClass::JavaClass() {
	this->c_name = "";
	this->name = "";
}

JavaClass::JavaClass(const std::string c_name, const std::string name) {
	this->c_name = c_name;
	this->name = name;
	this->jclass = jenv_ptr->FindClass(c_name.c_str());
	this->constructor_id = jenv_ptr->GetMethodID(jclass, "<init>", "()V");
}

JavaClass::~JavaClass() {
	std::for_each(this->jfields.begin(), this->jfields.end(), [](const std::pair<const std::string, jfieldID*>& pair) {
		delete pair.second;
	});
	std::for_each(this->jmethods.begin(), this->jmethods.end(), [](const std::pair<const std::string, jmethodID*>& pair) {
		delete pair.second;
	});
	this->jfields.clear();
	this->jmethods.clear();
}

jobject JavaClass::new_instance() {
	return jenv_ptr->NewObject(jclass, constructor_id);
}