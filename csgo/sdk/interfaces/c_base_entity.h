#pragma once

#include "../netvars/netvars.h"

class c_base_entity {
public:

	void* animating() {
		return reinterpret_cast<void*>(uintptr_t(this) + 0x4);
	}

	void* networkable() {
		return reinterpret_cast<void*>(uintptr_t(this) + 0x8);
	}

	bool is_player() {
		using func = bool (__thiscall*)(c_base_entity*);
		return (*(func**)this)[157](this);
	}

	bool is_weapon() {
		using func = bool(__thiscall*)(c_base_entity*);
		return (*(func**)this)[165](this);
	}

	c_base_entity* get_observer_target() {
		using func = c_base_entity* (__thiscall*)(c_base_entity*);
		return (*(func**)this)[294](this);
	}

	netvar_fn(spotted, "CBaseEntity->m_bSpotted", bool)
};
