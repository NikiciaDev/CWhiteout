#pragma once
#include <string>
#include <vector>
#include "Color.h"
#include "Setting.h"
#include "ConsoleUtil.h"

class Category final {
public:
    enum class Cat_E {
        COMBAT,
        MOVEMENT,
        PLAYER,
        EXPLOIT,
        OTHER,
        VISUAL,
        UNDECLARED
    };

    Cat_E cat_e{ Cat_E::UNDECLARED };

    Category();

    Category(const Cat_E cat_e);

    static Color get_color(const Category category);
};

class Module {
public:
    const Category category;
	std::string name{ "" };
    std::vector<Setting*> settings; // We do not need smart pointers here since only one object of the module should ever exist and only get freed on close.

    Module(const std::string name, const Category category);

    void init_settings(std::vector<Setting*>& settings);

    virtual void on_call();
};