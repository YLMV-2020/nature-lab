#pragma once
namespace Math {

	class __declspec(dllexport) Matrix
	{
	public:

		float matrix[4][4];

		Matrix();
		static Matrix identity();

		static Matrix translate(Matrix transform, const Vector& v1);
		static Matrix translate(Matrix transform, const int& dx, const int& dy, const int& dz);

		static Matrix scale(Matrix transform, const Vector& v1);
		static Matrix scale(Matrix transform, const int& px, const int& py, const int& pz);

		static Vector getPosition(Matrix& transform);
		static Vector getScale(Matrix& transform);

	};
}

