#include <Windows.h>

#include "input.h"

#include "../gui/gui.h"

bool input::is_holding(int keycode) {

	return GetAsyncKeyState(keycode);
}

bool input::click(int keycode) {

	return GetAsyncKeyState(keycode) & 1;
}

void input::handle() {

	// menu input handlers
	if (input::click(VK_INSERT)) {

		gui::is_open = !gui::is_open;
	}

	if (gui::is_open && input::click(VK_DOWN)) {

		if (gui::selected_item < gui::element_count - 1) {

			gui::selected_item += 1;
		}
	}
	else if (gui::is_open && input::click(VK_UP)) {

		if (gui::selected_item > 0) {

			gui::selected_item -= 1;
		}
	}
}