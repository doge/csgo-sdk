#pragma once

#include "c_base_entity.h"

#include "../netvars/netvars.h"

class c_base_player : public c_base_entity {
public:
	netvar_fn(flags, "CBasePlayer->m_fFlags", int)
};