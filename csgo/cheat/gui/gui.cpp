#include <Windows.h>
#include <iostream>

#include "gui.h"
#include "settings.h"

#include "../render/render.h"
#include "../render/fonts/fonts.h"

#include "../input/input.h"
#include "../../sdk/interfaces/variables.h"

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
		render::text(to_render.c_str(), 10 + 16, y_offset, fonts::tahoma, color(145, 219, 88, 255));
	}
	else {
		render::text(to_render.c_str(), 10 + 16, y_offset, fonts::tahoma);
	}

	// input handling
	if (selected_item == render_item && input::click(VK_RETURN)) {
		variable = !variable;
	}

	// add the height of the menu font plus some padding
	y_offset += interfaces::surface->get_font_tall(fonts::tahoma) + 2;
	render_item += 1;
}

void gui::render() {
	
	if (!gui::is_open) {
		return;
	}

	// reset vars
	gui::render_item = 0;
	gui::y_offset = 12 + 16;

	// the total amount of items to render
	gui::element_count = 3;

	// elements
	item("bhop", gui::settings::bhop);
	item("radar", gui::settings::radar);
	item("visuals", gui::settings::visuals);
}