#pragma once
#include "ModuleManager.h"
#include "Whiteout.h"

class GUI final {
private:
	const Whiteout* whiteout;

public:
	GUI(const Whiteout* whiteout);

	void draw_base();

	void draw_modules();

	// Call this function when a key is pressed;
	void on_mouse_event(const Key key);
};