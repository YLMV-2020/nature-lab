#pragma once

namespace Math {

	class __declspec(dllexport) Vector2
	{
	public:

		float x, y;

		Vector2();
		Vector2(float x);
		Vector2(float x, float y);

		friend Vector2 operator+(const Vector2& v1, const Vector2& v2) {
			return Vector2(v1.x + v2.x, v1.y + v2.y);
		}

		friend Vector2 operator+=(const Vector2& v1, const Vector2& v2) {
			return Vector2(v1.x + v2.x, v1.y + v2.y);
		}

		friend Vector2 operator-(const Vector2& v1, const Vector2& v2) {
			return Vector2(v1.x - v2.x, v1.y - v2.y);
		}
		friend Vector2 operator*(const Vector2& v1, const Vector2& v2);
		friend Vector2 operator*(const Vector2& v1, float scale) {
			return Vector2(v1.x * scale, v1.y * scale);
		}
		friend Vector2 operator/(Vector2 v1, Vector2 v2);
		friend Vector2 operator/(const Vector2& v1, const float& scale) {
			return Vector2(v1.x / scale, v1.y / scale);
		}
		friend Vector2 operator*(float scale, Vector2 v1);
		friend bool operator==(Vector2 v1, Vector2 v2);
		friend bool operator!=(Vector2 v1, Vector2 v2);

		static float point(Vector2 v1, Vector2 v2);
		static float magnitude(const Vector2& v1);
		static float magnitudeQuad(Vector2 v1);
		static Vector2 normalized(const Vector2& v1);
		static float angle(Vector2 v1, Vector2 v2);

		void add(const Vector2& v1);
		void normalized();

	};

}