#include "vec2.h"

#include <cmath>

namespace glxm
{
	vec2::vec2()
	{
		x = y = 0.0f;
	}

	vec2::vec2(float v)
	{
		this->x = this->y = v;
	}

	vec2::vec2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	float vec2::point(vec2 v1, vec2 v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	float vec2::magnitude(const vec2& v1)
	{
		return sqrt(v1.x * v1.x + v1.y * v1.y);
	}

	float vec2::magnitudeQuad(vec2 v1)
	{
		return v1.x * v1.x + v1.y * v1.y;
	}

	vec2 vec2::normalized(const vec2& v1)
	{
		float m = sqrt(v1.x * v1.x + v1.y * v1.y);
		return vec2(v1.x / m, v1.y / m);
	}

	float vec2::angle(vec2 v1, vec2 v2)
	{
		return 0.0f;
	}

	void vec2::add(const vec2& v1)
	{
		this->x += v1.x;
		this->y += v1.y;
	}

	void vec2::normalized()
	{
		float m = sqrt(x * x + y * y);
		x /= m;
		y /= m;
	}

}
