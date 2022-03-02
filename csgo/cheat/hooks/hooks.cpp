#include <iostream>

#include "hooks.h"

#include "../gui/gui.h"
#include "../gui/settings.h"

#include "../render/render.h"
#include "../render/fonts/fonts.h"

#include "../input/input.h"

#include "../../sdk/valve/flags.h"

#include "../../sdk/utilities/utils.h"

#include "../../sdk/interfaces/variables.h"
#include "../../sdk/interfaces/c_base_player.h"

#include "../../dependencies/minhook/MinHook.h"

#include "../../cheat/features/visuals.h"

void hooks::setup() {

	MH_Initialize();

	MH_CreateHook(
		*reinterpret_cast<void***>(interfaces::client_mode)[24],
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