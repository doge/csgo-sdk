#pragma once

#include "c_base_entity.h"

#include "../utilities/math.h"

#include "../netvars/netvars.h"

class c_base_player : public c_base_entity {
public:
	netvar_fn(flags, "CBasePlayer->m_fFlags", int)
	netvar_fn(health, "CBasePlayer->m_iHealth", int)
	netvar_fn(life_state, "CBasePlayer->m_lifeState", int)
	netvar_fn(account, "CCSPlayer->m_iAccount", int)
	netvar_fn(armor_value, "CCSPlayer->m_ArmorValue", int)
	netvar_fn(sequence, "CBaseViewModel->m_nSequence", int)

	netvar_fn(flash_duration, "CCSPlayer->m_flFlashDuration", float)
	netvar_fn(simulation_time, "CBaseEntity->m_flSimulationTime", float)
	netvar_fn(lby_target, "CCSPlayer->m_flLowerBodyYawTarget", float)

	netvar_fn(is_scoped, "CCSPlayer->m_bIsScoped", bool)
	netvar_fn(has_helmet, "CCSPlayer->m_bHasHelmet", bool)
	netvar_fn(has_heavy_armor, "CCSPlayer->m_bHasHeavyArmor", bool)
	netvar_fn(client_side_animation, "CBaseAnimating->m_bClientSideAnimation", bool)

	netvar_fn(abs_angles, "CBaseEntity->m_angAbsAngles", math::qangle_t)

	netvar_fn(vec_velocity, "CBasePlayer->m_vecVelocity[0]", math::vec3_t)
	netvar_fn(vec_view_offset, "CBasePlayer->m_vecViewOffset[0]", math::vec3_t)
	netvar_fn(view_punch_angle, "CBasePlayer->m_viewPunchAngle", math::vec3_t)
	netvar_fn(aim_punch_angle, "CBasePlayer->m_aimPunchAngle", math::vec3_t)
	netvar_fn(abs_origin, "CBaseEntity->m_angAbsOrigin", math::vec3_t)
};