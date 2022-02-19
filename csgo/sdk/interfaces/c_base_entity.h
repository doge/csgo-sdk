#pragma once

#include "c_base_player.h"

#include "../netvars/netvars.h"

class c_base_entity : public c_base_player {
public:
	netvar_fn(spotted, "CBaseEntity->m_bSpotted", bool)
};
