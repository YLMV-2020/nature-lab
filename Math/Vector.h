#pragma once

namespace Math {

	class __declspec(dllexport) Vector
	{
	public:

		float x, y, z, w;

		Vector();
		Vector(float x);
		Vector(float x, float y);
		Vector(float x, float y, float z);
		Vector(float x, float y, float z, float w);

		friend Vector operator+(const Vector& v1, const Vector& v2){
			return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
		}

		friend Vector operator+=(const Vector& v1, const Vector& v2) {
			return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
		}

		friend Vector operator-(const Vector& v1, const Vector& v2){
			return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
		}
		friend Vector operator*(Vector v1, Vector v2);
		friend Vector operator*(Vector v1, float scale) {
			return Vector(v1.x * scale, v1.y * scale, v1.z * scale);
		}
		friend Vector operator/(Vector v1, Vector v2);
		friend Vector operator/(const Vector &v1, const float &scale) {
			return Vector(v1.x / scale, v1.y / scale, v1.z / scale);
		}
		friend Vector operator*(float scale, Vector v1);
		friend bool operator==(Vector v1, Vector v2);
		friend bool operator!=(Vector v1, Vector v2);

		static float point(Vector v1, Vector v2);
		static float magnitude(Vector v1);
		static float magnitudeQuad(Vector v1);
		static Vector normalized(const Vector& v1);
		static float angle(Vector v1, Vector v2);

		void add(const Vector& v1);
		void normalized();

	};

}