#pragma once

namespace Math {

	class __declspec(dllexport) Vector3
	{
	public:

		float x, y, z, w;

		Vector3();
		Vector3(float x);
		Vector3(float x, float y, float z);
		Vector3(float x, float y, float z, float w);

		friend Vector3 operator+(const Vector3& v1, const Vector3& v2) {
			return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
		}

		friend Vector3 operator+=(const Vector3& v1, const Vector3& v2) {
			return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
		}

		friend Vector3 operator-(const Vector3& v1, const Vector3& v2) {
			return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
		}
		friend Vector3 operator*(const Vector3& v1, const Vector3& v2);
		friend Vector3 operator*(const Vector3& v1, float scale) {
			return Vector3(v1.x * scale, v1.y * scale, v1.z * scale);
		}
		friend Vector3 operator/(Vector3 v1, Vector3 v2);
		friend Vector3 operator/(const Vector3& v1, const float& scale) {
			return Vector3(v1.x / scale, v1.y / scale, v1.z / scale);
		}
		friend Vector3 operator*(float scale, Vector3 v1);
		friend bool operator==(Vector3 v1, Vector3 v2);
		friend bool operator!=(Vector3 v1, Vector3 v2);

		static float point(Vector3 v1, Vector3 v2);
		static float magnitude(const Vector3& v1);
		static float magnitudeQuad(Vector3 v1);
		static Vector3 normalized(const Vector3& v1);
		static float angle(Vector3 v1, Vector3 v2);

		void add(const Vector3& v1);
		void normalized();

	};

}