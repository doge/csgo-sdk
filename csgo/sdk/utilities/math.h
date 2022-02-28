#pragma once

#include <limits>

namespace math {

	struct vec2_t {

		float x, y;

		vec2_t() {
			x = y = 0.0f;
		}

		vec2_t(float x_in, float y_in) {
			x = x_in;
			y = y_in;
		}

		float& operator[](const std::size_t i) {

			return reinterpret_cast<float*>(this)[i];
		}

		vec2_t operator/(const vec2_t& divide) {

			float x = this->x / divide.x;
			float y = this->y / divide.y;

			return vec2_t(x, y);
		}

		vec2_t operator*(const vec2_t& multiply) {

			float x = this->x * multiply.x;
			float y = this->y * multiply.y;

			return vec2_t(x, y);
		}

		vec2_t operator+(const vec2_t& add) {

			float x = this->x + add.x;
			float y = this->y + add.y;

			return vec2_t(x, y);
		}

		vec2_t operator-(const vec2_t& subtract) {

			float x = this->x - subtract.x;
			float y = this->y - subtract.y;

			return vec2_t(x, y);
		}
	};

	struct vec3_t {

		float x, y, z;

		vec3_t() {

			x = y = z = 0.0f;
		}

		vec3_t(float x_in, float y_in, float z_in) {
			x = x_in;
			y = y_in;
			z = z_in;
		}

		float& operator[](const std::size_t i) {

			return reinterpret_cast<float*>(this)[i];
		}

		vec3_t operator/(const vec3_t& divide) {

			float x = this->x / divide.x;
			float y = this->y / divide.y;
			float z = this->z / divide.z;

			return vec3_t(x, y, z);
		}

		vec3_t operator*(const vec3_t& multiply) {

			float x = this->x * multiply.x;
			float y = this->y * multiply.y;
			float z = this->z * multiply.z;

			return vec3_t(x, y, z);
		}

		vec3_t operator+(const vec3_t& add) {

			float x = this->x + add.x;
			float y = this->y + add.y;
			float z = this->z + add.z;

			return vec3_t(x, y, z);
		}

		vec3_t operator-(const vec3_t& subtract) {

			float x = this->x - subtract.x;
			float y = this->y - subtract.y;
			float z = this->z - subtract.z;

			return vec3_t(x, y, z);
		}
	};

	struct qangle_t {

		float x, y, z;

		qangle_t() {

			x = y = z = 0.0f;
		}

		float& operator[] (const std::size_t i) {

			return reinterpret_cast<float*>(this)[i];
		}
	};
}