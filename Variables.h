#pragma once
#include <map>
#include <jni.h>
#include "Whiteout.h"
#include "Module.h"
#include "Command.h"
#include "WGUI.h"

namespace ModuleManager {
	std::map<const std::string, Module*> modules;

	std::vector<Module*> c_modules;
	std::vector<Module*> m_modules;
	std::vector<Module*> p_modules;
	std::vector<Module*> v_modules;
	std::vector<Module*> e_modules;
}

namespace CommandManager {
	std::map<const std::string, Command*> commands;
}

namespace font {
	sf::Font meb, mb, mm, mr;
}

std::vector<std::string> mdcn_a;
std::vector<sf::Color> mdcc_a; // Use the coresponding function to retrieve value!
Whiteout* whiteout;
JavaVM* jvm_ptr{ nullptr };
JNIEnv* jenv_ptr{ nullptr };
std::map<const std::string, JavaClass*> classes;

void init_variables(const std::string font_path);

void clean_variables();

sf::Color mdcc(unsigned short index);