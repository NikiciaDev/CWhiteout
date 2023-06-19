#include "JavaClass.h"

JavaClass::JavaClass() {
	this->c_name = "";
	this->name = "";
	this->jclass = NULL;
}

JavaClass::JavaClass(const char* c_name, const char* name) {
	this->c_name = c_name;
	this->name = name;
	this->jclass = jenv_ptr->FindClass(c_name);
}

JavaClass::~JavaClass() {
	free((char*) this->c_name);
	free((char*) this->name);
}