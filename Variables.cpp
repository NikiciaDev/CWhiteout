#include "Variables.h"

void init_variables() {
    JNI_GetCreatedJavaVMs(&jvm_ptr, 1, nullptr);
    jvm_ptr->AttachCurrentThread((void**) &jenv_ptr, nullptr);
}
