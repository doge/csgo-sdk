#pragma once

class i_engine_client
{
public:
	// 0x12
	int local_player()
	{
		using func = int (__thiscall*)(i_engine_client*);
		return (*(func**)this)[12](this);
	};
};

inline i_engine_client* g_engine_client;