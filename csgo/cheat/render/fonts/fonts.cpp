#include "fonts.h"

#include "../../../sdk/interfaces/variables.h"

void fonts::setup() {

	tahoma = interfaces::surface->create_font();
	interfaces::surface->set_font_glyph_set(tahoma, "Tahoma", 16, 100, 0, 0, e_font_flags::fontflag_none);
}