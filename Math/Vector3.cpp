#include "pch.h"
#include "Vector3.h"

namespace Math
{
	Vector3::Vector3()
	{
		x = y = z = 0.0f;
		w = 1.0f;
	}

	Vector3::Vector3(float x)
	{
		this->x = this->y = this->z = this->w = x;
	}

	Vector3::Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = 1.0f;
	}

	Vector3::Vector3(float x, float y, float z, float w)
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

	float Vector3::point(Vector3 v1, Vector3 v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	float Vector3::magnitude(const Vector3& v1)
	{
		return sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
	}

	float Vector3::magnitudeQuad(Vector3 v1)
	{
		return v1.x * v1.x + v1.y * v1.y + v1.z * v1.z;
	}

	Vector3 Vector3::normalized(const Vector3& v1)
	{
		float m = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
		return Vector3(v1.x / m, v1.y / m, v1.z / m);
	}

	float Vector3::angle(Vector3 v1, Vector3 v2)
	{
		return 0.0f;
	}

	void Vector3::add(const Vector3& v1)
	{
		this->x += v1.x;
		this->y += v1.y;
		this->z += v1.z;
	}

	void Vector3::normalized()
	{
		float m = sqrt(x * x + y * y + z * z);
		x /= m;
		y /= m;
		z /= m;
	}



}