#include <Windows.h>

#include "input.h"

#include "../gui/gui.hpp"

void input::update() {

	for (int i = 0; i < 256; i++) {
		click_key_states[i] = GetAsyncKeyState(i) & 1;
		hold_key_states[i] = GetAsyncKeyState(i);
	}
}

bool input::is_holding(int keycode) {

	return hold_key_states[keycode];
}

bool input::click(int keycode) {

	return click_key_states[keycode];
}

void input::handle() {

	// gui
	if (input::click(VK_INSERT)) {
		gui::is_open = !gui::is_open;
	}
}