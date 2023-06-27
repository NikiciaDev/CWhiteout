#pragma once
#include "ModuleManager.h"
#include "Whiteout.h"
#include "FontRenderer.h"
#include "RenderUtil.h"

class GUI final {
private:
	Whiteout* whiteout;

public:
	GUI(Whiteout* whiteout);

	void draw_base();

	void draw_modules();

	// Call this function when a key is pressed;
	void on_mouse_event(const Key key);
};