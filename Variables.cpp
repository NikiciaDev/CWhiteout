#include "Variables.h"

void init_variables(const std::string font_path) {
    JNI_GetCreatedJavaVMs(&jvm_ptr, 1, nullptr);
    jvm_ptr->AttachCurrentThread((void**) &jenv_ptr, nullptr);
    whiteout = new Whiteout(Whiteout::name_build, 4, 1000, 600);
    if (!frr::rmb.loadFromFile(font_path + "\\RobotoMono-Bold.ttf")) print_err("Failed to load RMB font\n");
    if (!frr::rmm.loadFromFile(font_path + "\\RobotoMono-Medium.ttf")) print_err("Failed to load RMM font\n");
    if (!frr::rmr.loadFromFile(font_path + "\\RobotoMono-Regular.ttf")) print_err("Failed to load RMR font\n");
    if (!frr::rmt.loadFromFile(font_path + "\\RobotoMono-Thin.ttf")) print_err("Failed to load RMT font\n");
}
