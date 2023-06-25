#include "Setting.h"

Setting::Setting(const std::string name, const std::shared_ptr<Module> parent, const SETTING_TYPE type) : name(name), parent(parent), type(type) { }