#pragma once

#include "../netvars/netvars.h"

#include "../utilities/math.h"

class c_base_entity {

public:

	struct networkable_t {

		bool dormant() {

			using func = bool(__thiscall*)(networkable_t*);
			return (*(func**)this)[0x9](this);
		}

		int index() {

			using func = int(__thiscall*)(networkable_t*);
			return (*(func**)this)[0xA](this);
		}
	};

	void* animating() {

		return reinterpret_cast<void*>(uintptr_t(this) + 0x4);
	}

	networkable_t* networkable() {

		return reinterpret_cast<networkable_t*>(uintptr_t(this) + 0x8);
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

	netvar_fn(vec_mins, "CBaseEntity->m_vecMins", math::vec3_t)
	netvar_fn(vec_maxs, "CBaseEntity->m_vecMaxs", math::vec3_t)
	netvar_fn(vec_origin, "CBaseEntity->m_vecOrigin", math::vec3_t)
	netvar_fn(vec_angles, "CBaseEntity->m_vecAngles", math::vec3_t)
};
