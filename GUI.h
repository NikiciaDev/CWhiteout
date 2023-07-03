#pragma once
#include "ModuleManager.h"
#include "Whiteout.h"
#include "FontRenderer.h"
#include "RenderUtil.h"
#include "Terminal.h"
#include "CategorySelectionButton.h"
#include "ColorSetting.h"
#include "ModeSetting.h"
#include "StringSetting.h"
#include "DrawableBool.h"
#include "DrawableColor.h"
#include "DrawableMode.h"
#include "DrawableNumber.h"
#include "DrawableString.h"

extern std::map<const std::string, JavaClass*> classes;

class GUI final {
private:
	Whiteout* whiteout;
	std::map<Module*, std::pair<sf::FloatRect, sf::FloatRect>> m_names;

public:
	CategorySelectionButton csb;
	Terminal terminal;

	GUI(Whiteout* whiteout);

	void draw_base();

	void draw_modules();

	// Call this function when a key is pressed;
	void on_key_event(const Key key);
};