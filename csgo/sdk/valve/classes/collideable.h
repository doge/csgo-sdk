#pragma once

#include "../../interfaces/c_user_cmd.h"

class collideable_t {

public:
	math::vec3_t& mins() {
		using fn = math::vec3_t& (__thiscall*)(void*);
		return (*(fn**)this)[1](this);
	}

	math::vec3_t& maxs() {
		using fn = math::vec3_t& (__thiscall*)(void*);
		return (*(fn**)this)[2](this);
	}
};