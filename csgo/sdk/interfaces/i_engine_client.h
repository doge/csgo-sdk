#pragma once

#include "c_user_cmd.h"

class i_engine_client
{
public:

	void screen_size(int& width, int& height) {
		using fn = void(__thiscall*)(i_engine_client*, int&, int&);
		return (*(fn**)this)[5](this, width, height);
	}

	int local_player() {
		using fn = int (__thiscall*)(i_engine_client*);
		return (*(fn**)this)[12](this);
	};

	void view_angles(math::vec3_t& view) {
		using fn = void (__thiscall*)(i_engine_client*, math::vec3_t&);
		return (*(fn**)this)[18](this, view);
	}

	void set_view_angles(math::vec3_t& view) {
		using fn = void (__thiscall*)(i_engine_client*, math::vec3_t&);
		return (*(fn**)this)[19](this, view);
	}

	int max_clients() {
		using fn = int (__thiscall*)(i_engine_client*);
		return (*(fn**)this)[20](this);
	}

	bool is_in_game() {
		using fn = bool (__thiscall*)(i_engine_client*);
		return (*(fn**)this)[26](this);
	}

	void execute_client_cmd(const char* command) {
		using fn = void (__thiscall*)(i_engine_client*);
		return (*(fn**)this)[108](this);
	};

	void client_cmd_unrestricted(const char* command) {
		using fn = void (__thiscall*)(i_engine_client*, const char*, bool);
		return (*(fn**)this)[114](this, command, false);
	};
};