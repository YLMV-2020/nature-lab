#include "pch.h"
#include "Vector2.h"

namespace Math
{
	Vector2::Vector2()
	{
		x = y = 0.0f;
	}

	Vector2::Vector2(float v)
	{
		this->x = this->y = v;
	}

	Vector2::Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	

	float Vector2::point(Vector2 v1, Vector2 v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	float Vector2::magnitude(const Vector2& v1)
	{
		return sqrt(v1.x * v1.x + v1.y * v1.y);
	}

	float Vector2::magnitudeQuad(Vector2 v1)
	{
		return v1.x * v1.x + v1.y * v1.y;
	}

	Vector2 Vector2::normalized(const Vector2& v1)
	{
		float m = sqrt(v1.x * v1.x + v1.y * v1.y);
		return Vector2(v1.x / m, v1.y / m);
	}

	float Vector2::angle(Vector2 v1, Vector2 v2)
	{
		return 0.0f;
	}

	void Vector2::add(const Vector2& v1)
	{
		this->x += v1.x;
		this->y += v1.y;
	}

	void Vector2::normalized()
	{
		float m = sqrt(x * x + y * y);
		x /= m;
		y /= m;
	}

}