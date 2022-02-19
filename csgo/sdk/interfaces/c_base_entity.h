#pragma once

#include "../netvars/netvars.h"

class c_base_entity
{
public:
	netvar_fn(spotted, "CBaseEntity->m_bSpotted", bool)
	netvar_fn(flags, "CBasePlayer->m_fFlags", int)
};
