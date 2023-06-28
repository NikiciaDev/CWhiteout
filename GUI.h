#pragma once
#include "ModuleManager.h"
#include "Whiteout.h"
#include "FontRenderer.h"
#include "RenderUtil.h"
#include "Terminal.h"
#include "CategorySelectionButton.h"

class GUI final {
private:
	Whiteout* whiteout;

public:
	CategorySelectionButton csb;
	Terminal terminal;

	GUI(Whiteout* whiteout);

	void draw_base();

	void draw_modules();

	// Call this function when a key is pressed;
	void on_key_event(const Key key);
};