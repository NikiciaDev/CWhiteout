#pragma once
#include <jni.h>
#include "JavaClass.h"

extern std::map<const std::string, JavaClass*> classes;

inline JavaClass* get_minecraft() {
	return classes.find("Minecraft")->second;
}

inline JavaClass* get_player() {
	return classes.find("EntityPlayerSp")->second;
}

inline JavaClass* get_world() {
	return classes.find("WorldClient")->second;
}

inline JavaClass* get_timer() {
	return classes.find("Timer")->second;
}

inline JavaClass* get_game_settings() {
	return classes.find("GameSettings")->second;
}

inline JavaClass* get_moving_object_position() {
	return classes.find("MovingObjPos")->second;
}

inline unsigned short get_ev(const std::string qenum, const jobject enum_instance) {
	jclass jc = jenv_ptr->FindClass(qenum.c_str());
	return jenv_ptr->CallIntMethod(enum_instance, jenv_ptr->GetMethodID(jc, "ordinal", "()I"));
}

// This will invalidate object!
inline std::string jobj_to_string(jobject& object) {
	const char* nativeString = jenv_ptr->GetStringUTFChars((jstring) object, 0);
	std::string ret(nativeString);
	jenv_ptr->ReleaseStringUTFChars((jstring) object, nativeString);
	return ret;
}