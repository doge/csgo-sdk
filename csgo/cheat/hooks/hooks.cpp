#include <iostream>

#include "hooks.h"

#include "../../sdk/interfaces/variables.h"
#include "../../dependencies/minhook/MinHook.h"
#include "../../sdk/interfaces/c_base_entity.h"

#include "../../sdk/valve/flags.h"

void hooks::setup() {

	MH_Initialize();

	MH_CreateHook(
		(*static_cast<void***>(interfaces::client_mode))[24],
		&hooks::create_move,
		reinterpret_cast<void**>(&original_create_move)
	);

	MH_EnableHook(MH_ALL_HOOKS);
}

void hooks::destroy() {

	MH_DisableHook(MH_ALL_HOOKS);
	MH_RemoveHook(MH_ALL_HOOKS);
	MH_Uninitialize();
}

bool __stdcall hooks::create_move(float frame_time, c_user_cmd* cmd) {

	const bool result = original_create_move(interfaces::client_mode, frame_time, cmd);

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