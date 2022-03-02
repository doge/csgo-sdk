#include "hooks.h"

#include "../../sdk/interfaces/variables.h"

#include "../render/fonts/fonts.h"

void __stdcall hooks::screen_size_changed(int previous_width, int previous_height) {

	o_screen_size_changed_hook(interfaces::surface, previous_width, previous_height);

	// re-setup fonts when the resolution is changed
	fonts::setup();
}