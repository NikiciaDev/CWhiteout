#pragma once
#include <string>
#include "Module.h"
#include "Color.h"
#include "ConsoleUtil.h"

enum class S_Category {
    NUMBER,
    BOOLEAN,
    MODE,
    COLOR,
    STRING,
    UNDECLARED
};

class Setting {
public:
    S_Category category{ S_Category::UNDECLARED };
    Module parent;
    std::string name{ "" };

    Setting(const std::string name, const Module parent);
};