#pragma once

#include "../../sdk/interfaces/c_user_cmd.h"

namespace hooks {

	void setup();
	void destroy();

	bool __stdcall create_move(float frame_time, c_user_cmd* cmd);

	using create_move_hook = bool(__thiscall*)(void*, float, c_user_cmd*);
	static create_move_hook original_create_move = nullptr;
}