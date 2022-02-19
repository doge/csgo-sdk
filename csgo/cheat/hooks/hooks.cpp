#include <iostream>

#include "hooks.h"

#include "../../sdk/valve/flags.h"

#include "../../sdk/interfaces/variables.h"
#include "../../sdk/interfaces/c_base_entity.h"

#include "../../dependencies/minhook/MinHook.h"

#include "../render/render.h"
#include "../render/fonts/fonts.h"

void hooks::setup() {

	MH_Initialize();

	MH_CreateHook(
		(*static_cast<void***>(interfaces::client_mode))[24],
		&hooks::create_move,
		reinterpret_cast<void**>(&o_create_move_hook)
	);

	MH_CreateHook(
		reinterpret_cast<void*>(static_cast<unsigned int>((*reinterpret_cast<int**>(interfaces::vgui_panel))[41])),
		&hooks::paint_traverse,
		reinterpret_cast<void**>(&o_paint_traverse_hook)
	);

	MH_CreateHook(
		reinterpret_cast<void*>(static_cast<unsigned int>((*reinterpret_cast<int**>(interfaces::surface))[116])),
		&hooks::screen_size_changed,
		reinterpret_cast<void**>(&o_screen_size_changed_hook)
	);


	MH_EnableHook(MH_ALL_HOOKS);
}

void hooks::destroy() {

	MH_DisableHook(MH_ALL_HOOKS);
	MH_RemoveHook(MH_ALL_HOOKS);
	MH_Uninitialize();
}

bool __stdcall hooks::create_move(float frame_time, c_user_cmd* cmd) {

	const bool result = o_create_move_hook(interfaces::client_mode, frame_time, cmd);

	if (!cmd || !cmd->command_number) {
		return result;
	}

	auto local_player = reinterpret_cast<c_base_entity*>(interfaces::entity_list->get_client_entity(interfaces::engine->local_player()));

	// bhop
	if (cmd->buttons & command_buttons::in_jump && !(local_player->flags() & entity_flags::fl_onground)) {
		cmd->buttons &= ~command_buttons::in_jump;
	}

	return result;	
}

void __stdcall hooks::paint_traverse(unsigned int panel, bool force_repaint, bool allow_force) {

	// make sure we render on the top panel
	if (fnv::hash(interfaces::vgui_panel->get_class_name(panel)) == fnv::hash("MatSystemTopPanel")) {

		// do rendering here
		render::text("csgo-sdk", 10, 10, fonts::tahoma, color(255, 255, 255, 255));
	}

	o_paint_traverse_hook(interfaces::vgui_panel, panel, force_repaint, allow_force);
}

void __stdcall hooks::screen_size_changed(int previous_width, int previous_height) {

	o_screen_size_changed_hook(interfaces::surface, previous_width, previous_height);

	// re-setup fonts when the resolution is changed
	fonts::setup();
}