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
	
}

jobject JavaClass::new_instance() {
	return jenv_ptr->NewObject(jclass, constructor_id);
}