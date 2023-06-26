#include "Variables.h"

void init_variables() {
    JNI_GetCreatedJavaVMs(&jvm_ptr, 1, nullptr);
    jvm_ptr->AttachCurrentThread((void**) &jenv_ptr, nullptr);
    whiteout = new Whiteout(Whiteout::name_build, 2, 1000, 600);
}
