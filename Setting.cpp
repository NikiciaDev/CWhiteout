#include "Setting.h"

Setting::Setting(const std::string name, const std::shared_ptr<Module> parent, const stg::SETTING_TYPE type) : name(name), parent(parent), type(type) { }