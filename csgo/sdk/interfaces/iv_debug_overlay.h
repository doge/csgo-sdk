#pragma once

#include "../utilities/math.h"

class iv_debug_overlay {
public:

	bool world_to_screen(const math::vec3_t& input, const math::vec3_t& output) {

		using func = int(__thiscall*)(iv_debug_overlay*, const math::vec3_t&, const math::vec3_t&);
		return static_cast<bool>((*(func**)this)[13](this, input, output) != 1);
	}
};