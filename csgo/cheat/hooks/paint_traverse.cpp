#include "hooks.h"

#include "../../sdk/interfaces/variables.h"

#include "../render/render.h"
#include "../render/fonts/fonts.h"

#include "../gui/gui.h"
#include "../gui/settings.h"

#include "../features/visuals.h"

void __stdcall hooks::paint_traverse(unsigned int panel, bool force_repaint, bool allow_force) {

	auto panel_name = fnv::hash(interfaces::vgui_panel->get_class_name(panel));

	// do rendering on the top panel
	if (panel_name == fnv::hash("MatSystemTopPanel")) {

		render::text("csgo-sdk", 10, 10, fonts::tahoma);

		gui::render();

		if (gui::settings::visuals) {

			visuals::render();
		}
	}
	else if (panel_name == fnv::hash("FocusOverlayPanel")) {

		interfaces::vgui_panel->mouse_input_enabled(panel, gui::is_open);
		interfaces::vgui_panel->keyboard_input_enabled(panel, gui::is_open);
	}

	o_paint_traverse_hook(interfaces::vgui_panel, panel, force_repaint, allow_force);
}