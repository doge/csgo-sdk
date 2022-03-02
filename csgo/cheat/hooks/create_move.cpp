#include "hooks.h"

#include "../../sdk/interfaces/variables.h"
#include "../../sdk/interfaces/c_base_player.h"

#include "../../sdk/valve/flags.h"

#include "../gui/settings.h"

bool __stdcall hooks::create_move(float frame_time, c_user_cmd* cmd) {

	const bool result = o_create_move_hook(interfaces::client_mode, frame_time, cmd);

	if (!cmd || !cmd->command_number) {
		return result;
	}

	auto local_player = reinterpret_cast<c_base_player*>(interfaces::entity_list->get_client_entity(interfaces::engine->local_player()));

	// bhop
	if (gui::settings::bhop) {

		if (cmd->buttons & command_buttons::in_jump &&
			!(local_player->flags() & entity_flags::fl_onground)) {

			cmd->buttons &= ~command_buttons::in_jump;
		}
	}

	return result;
}