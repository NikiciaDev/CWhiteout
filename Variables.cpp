#include "Variables.h"

void init_variables(const std::string font_path) {
    JNI_GetCreatedJavaVMs(&jvm_ptr, 1, nullptr);
    jvm_ptr->AttachCurrentThread((void**) &jenv_ptr, nullptr);
    whiteout = new Whiteout(Whiteout::name_build, 4, 1000, 600);
    mdcn_a = { "TERMINAL", "COMBAT", "MOVEMENT", "PLAYER", "VISUAL", "EXPLOIT" };
    mdcc_a = { sf::Color(255, 255, 255), sf::Color(245, 91, 58), sf::Color(34, 184, 113), sf::Color(147, 82, 176), sf::Color(57, 18, 214), sf::Color(51, 144, 203) };
    if (!font::meb.loadFromFile(font_path + "\\Mukta-ExtraBold.ttf")) print_err("Failed to load meb font\n");
    if (!font::mb.loadFromFile(font_path + "\\Mukta-Bold.ttf")) print_err("Failed to load mb font\n");
    if (!font::mm.loadFromFile(font_path + "\\Mukta-Medium.ttf")) print_err("Failed to load mm font\n");
    if (!font::mr.loadFromFile(font_path + "\\Mukta-Regular.ttf")) print_err("Failed to load mr font\n");
    font::meb.setSmooth(false);
    font::mb.setSmooth(false);
    font::mm.setSmooth(false);
    font::mr.setSmooth(false);
}

void clean_variables() {
    jvm_ptr->DetachCurrentThread();

    std::for_each(classes.begin(), classes.end(), [](const std::pair<const std::string, JavaClass*>& pair) {
        delete pair.second;
    });
    classes.clear();

    font::meb.~Font();
    font::mb.~Font();
    font::mm.~Font();
    font::mr.~Font();
    delete whiteout;
}

sf::Color mdcc(unsigned short index) {
    WGUI* gui_ptr = static_cast<WGUI*>(ModuleManager::modules.find("GUI")->second);
    if (gui_ptr->category_colors.gv<bool>()) {
        return mdcc_a[index];
    }
    
    return gui_ptr->base_color.gv<sf::Color>();
}
