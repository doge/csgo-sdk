#include <Windows.h>
#include <iostream>

#include "gui.h"
#include "settings.h"

#include "../render/render.h"
#include "../render/fonts/fonts.h"

#include "../input/input.h"

void gui::item(const char* name, bool& variable) {

	std::string to_render;

	if (selected_item == render_item) {
		
		// concatenate cursor
		std::string concat;

		concat = "-> ";
		concat += name;

		to_render = concat;
	}
	else {
		to_render = name;
	}

	// item rendering
	if (variable) {
		render::text(to_render.c_str(), 10 + 16, gui::y_offset, fonts::tahoma, color(145, 219, 88, 255));
	}
	else {
		render::text(to_render.c_str(), 10 + 16, gui::y_offset, fonts::tahoma);
	}

	// input handling
	if (gui::selected_item == gui::render_item && input::click(VK_RETURN)) {
		variable = !variable;
	}

	// add the height of font::tahoma + 2
	gui::y_offset += 16 + 2;
	render_item += 1;
}

void gui::render() {
	
	if (!gui::is_open) {
		return;
	}

	// reset the y offset and the index of the item
	// we're currently rendering
	gui::render_item = 0;
	gui::y_offset = 12 + 16;

	// the count of the amount of items we're rendering
	gui::element_count = 2;

	// elements
	item("bhop", gui::settings::bhop);
	item("radar", gui::settings::radar);
}