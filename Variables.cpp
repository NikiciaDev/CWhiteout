#include "Variables.h"

void init_variables(const std::string font_path) {
    JNI_GetCreatedJavaVMs(&jvm_ptr, 1, nullptr);
    jvm_ptr->AttachCurrentThread((void**) &jenv_ptr, nullptr);
    whiteout = new Whiteout(Whiteout::name_build, 4, 1000, 600);
    if (!font::meb.loadFromFile(font_path + "\\Mukta-ExtraBold.ttf")) print_err("Failed to load meb font\n");
    if (!font::mb.loadFromFile(font_path + "\\Mukta-Bold.ttf")) print_err("Failed to load mb font\n");
    if (!font::mm.loadFromFile(font_path + "\\Mukta-Medium.ttf")) print_err("Failed to load mm font\n");
    if (!font::mr.loadFromFile(font_path + "\\Mukta-Regular.ttf")) print_err("Failed to load mr font\n");
    //font::meb.setSmooth(false);
    //font::mb.setSmooth(false);
    //font::mm.setSmooth(false);
    //font::mr.setSmooth(false);
}
