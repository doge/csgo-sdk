#pragma once

#include "c_user_cmd.h"

#include <stdint.h>

struct player_info_t
{
	uint64_t unknown;

	union
	{
		uint64_t xuid;
		struct
		{
			uint32_t xuid_low;
			uint32_t xuid_high;
		};
	};

	char name[128];
	int	 id;
	char steam_id[33];
	unsigned long friends_id;
	char friends_name[128];
	bool fake_player;
	bool is_hltv;
	unsigned long custom_files[4];
	unsigned char files_downloaded;
};

class i_engine_client
{
public:

	void screen_size(int& width, int& height) {

		using fn = void(__thiscall*)(i_engine_client*, int&, int&);
		return (*(fn**)this)[5](this, width, height);
	};

	bool get_player_info(int ent_index, player_info_t& player_info) {

		using fn = bool(__thiscall*)(i_engine_client*, int, player_info_t&);
		return (*(fn**)this)[8](this, ent_index, player_info);
	};

	int local_player() {

		using fn = int(__thiscall*)(i_engine_client*);
		return (*(fn**)this)[12](this);
	};

	void view_angles(math::vec3_t& view) {

		using fn = void(__thiscall*)(i_engine_client*, math::vec3_t&);
		return (*(fn**)this)[18](this, view);
	};

	void set_view_angles(math::vec3_t& view) {

		using fn = void(__thiscall*)(i_engine_client*, math::vec3_t&);
		return (*(fn**)this)[19](this, view);
	};

	int max_clients() {

		using fn = int(__thiscall*)(i_engine_client*);
		return (*(fn**)this)[20](this);
	};

	bool is_in_game() {

		using fn = bool(__thiscall*)(i_engine_client*);
		return (*(fn**)this)[26](this);
	};

	void execute_client_cmd(const char* command) {

		using fn = void (__thiscall*)(i_engine_client*);
		return (*(fn**)this)[108](this);
	};

	void client_cmd_unrestricted(const char* command) {

		using fn = void (__thiscall*)(i_engine_client*, const char*, bool);
		return (*(fn**)this)[114](this, command, false);
	};
};