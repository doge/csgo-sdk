#pragma once

#include "../netvars/netvars.h"

#include "../utilities/math.h"

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

	netvar_fn(team_num, "CBaseEntity->m_iTeamNum", int)
	netvar_fn(model_index, "CBaseEntity->m_nModelIndex", int)

	netvar_fn(spotted, "CBaseEntity->m_bSpotted", bool)
	netvar_fn(should_glow, "CBaseEntity->m_bShouldGlow", bool)

	netvar_fn(anim_time, "CBaseEntity->m_flAnimTime", float)

	netvar_fn(vec_mins, "CBaseEntity->m_vecMins", vec3_t)
	netvar_fn(vec_maxs, "CBaseEntity->m_vecMaxs", vec3_t)
	netvar_fn(vec_origin, "CBaseEntity->m_vecOrigin", vec3_t)
	netvar_fn(vec_angles, "CBaseEntity->m_vecAngles", vec3_t)
};
