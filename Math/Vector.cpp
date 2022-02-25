#include "pch.h"
#include "Vector.h"

namespace Math
{
	Vector::Vector()
	{
		x = y = 0.0f;
		z = w = 1.0f;
	}

	Vector::Vector(float x)
	{
		this->x = this->y = this->z = this->w = x;
	}

	Vector::Vector(float x, float y)
	{
		this->x = x;
		this->y = y;
		this->z = 1.0f;
		this->w = 1.0f;
	}

	Vector::Vector(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = 1.0f;
	}

	Vector::Vector(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	/*Vector operator+(Vector v1, Vector v2)
	{
		return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	}*/


	//Vector Vector::operator-(Vector v1, Vector v2)
 //{
 //	return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
 //}
 //Vector Vector::operator*(Vector v1, Vector v2)
 //{
 //	return Vector(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
 //}
 //Vector Vector::operator*(Vector v1, float scale)
 //{
 //	return Vector(v1.x * scale, v1.y * scale, v1.z * scale);
 //}
 //Vector Vector::operator*(float scale, Vector v1)
 //{
 //	return Vector(v1.x * scale, v1.y * scale, v1.z * scale);
 //}
 //bool Vector::operator==(Vector v1, Vector v2)
 //{
 //	return false;
 //}
 //bool Vector::operator!=(Vector v1, Vector v2)
 //{
 //	return false;
 //}

	float Vector::point(Vector v1, Vector v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	float Vector::magnitude(const Vector &v1)
	{
		return sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
	}

	float Vector::magnitudeQuad(Vector v1)
	{
		return v1.x * v1.x + v1.y * v1.y + v1.z * v1.z;
	}

	Vector Vector::normalized(const Vector& v1)
	{
		float m = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
		return Vector(v1.x / m, v1.y / m, v1.z / m);
	}

	float Vector::angle(Vector v1, Vector v2)
	{
		return 0.0f;
	}

	void Vector::add(const Vector& v1)
	{
		this->x += v1.x;
		this->y += v1.y;
		this->z += v1.z;
	}

	void Vector::normalized()
	{
		float m = sqrt(x * x + y * y + z * z);
		x /= m;
		y /= m;
		z /= m;
	}



}