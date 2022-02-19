#pragma once

#include "../../sdk/interfaces/c_user_cmd.h"

namespace hooks {

	void setup();
	void destroy();

	bool __stdcall create_move(float frame_time, c_user_cmd* cmd);
	using create_move_hook = bool(__thiscall*)(void*, float, c_user_cmd*);
	static create_move_hook o_create_move_hook = nullptr;

	void __stdcall paint_traverse(unsigned int panel, bool force_repaint, bool allow_force);
	using paint_traverse_hook = void(__thiscall*)(void*, unsigned int, bool, bool);
	static paint_traverse_hook o_paint_traverse_hook = nullptr;
}