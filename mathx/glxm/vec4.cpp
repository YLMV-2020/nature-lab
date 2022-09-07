#include "vec4.h"

#include <cmath>

namespace glxm
{
	vec4::vec4()
	{
		x = y = z = 0.0f;
		w = 1.0f;
	}

	vec4::vec4(float x)
	{
		this->x = this->y = this->z = this->w = x;
	}

	vec4::vec4(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = 1.0f;
	}

	vec4::vec4(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	float vec4::point(vec4 v1, vec4 v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	float vec4::magnitude(const vec4& v1)
	{
		return sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
	}

	float vec4::magnitude_quad(vec4 v1)
	{
		return v1.x * v1.x + v1.y * v1.y + v1.z * v1.z;
	}

	vec4 vec4::normalized(const vec4& v1)
	{
		const float m = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
		return {v1.x / m, v1.y / m, v1.z / m};
	}

	float vec4::angle(vec4 v1, vec4 v2)
	{
		return 0.0f;
	}

	void vec4::add(const vec4& v1)
	{
		this->x += v1.x;
		this->y += v1.y;
		this->z += v1.z;
	}

	void vec4::normalized()
	{
		const float m = sqrt(x * x + y * y + z * z);
		x /= m;
		y /= m;
		z /= m;
	}



}
