#include "JavaClass.h"

JavaClass::JavaClass() {
	this->c_name = "";
	this->name = "";
}

JavaClass::JavaClass(const char* c_name, const char* name) {
	this->c_name = c_name;
	this->name = name;
	this->jclass = jenv_ptr->FindClass(c_name);
	this->constructor_id = jenv_ptr->GetMethodID(jclass, "<init>", "()V");
}

JavaClass::~JavaClass() {
	free((char*) this->c_name);
	free((char*) this->name);
}

jobject JavaClass::new_instance() {
	return jenv_ptr->NewObject(jclass, constructor_id);
}