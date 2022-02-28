#pragma once

namespace math {

	struct vec3_t {
		float x, y, z;

		vec3_t() {
			x = y = z = 0.0f;
		}
	};

	struct qangle_t {
		float x, y, z;

		qangle_t() {
			x = y = z = 0.0f;
		}
	};

}