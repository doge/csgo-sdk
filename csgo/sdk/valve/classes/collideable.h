#pragma once

#include "../../interfaces/c_user_cmd.h"

class collideable_t {

public:
	vec3_t& maxs() {
		using fn = vec3_t& (__thiscall*)(void*);
		return (*(fn**)this)[2](this);
	}

	vec3_t& mins() {
		using fn = vec3_t& (__thiscall*)(void*);
		return (*(fn**)this)[1](this);
	}
};