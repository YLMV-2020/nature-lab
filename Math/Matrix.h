#pragma once
namespace Math {

	class __declspec(dllexport) Matrix
	{
	private:

		//static std::queue<Matrix> transformations;

	public:

		float _m[4][4];

		Matrix();
		Matrix(int n);

		static Matrix identity();

		static Matrix translate(Matrix transform, const Vector& v1);
		static Matrix translate(Matrix transform, const int& dx, const int& dy, const int& dz);

		static Matrix scale(Matrix transform, const Vector& v1);
		static Matrix scale(Matrix transform, const int& px, const int& py, const int& pz);

		static Matrix rotationAroundX(Matrix transform, const float& angle);
		static Matrix rotationAroundY(Matrix transform, const float& angle);
		static Matrix rotationAroundZ(Matrix transform, const float& angle);

		static Matrix rotation(float x, float y, float z);

		static Matrix ortho(Matrix transform, float left, float right, float bottom, float top, float zNear, float zFar);

		static Vector getPosition(Matrix& transform);
		static Vector getScale(Matrix& transform);

		/*static void pushMatrix(const Matrix& transform);
		static Matrix popMatrix();*/

		friend Matrix operator*(const Matrix& m1, const Matrix& m2)
		{
			Matrix result = Matrix();
			result.identity();

			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					for (int k = 0; k < 4; k++)
					{
						result._m[i][j] += m1._m[i][k] * m2._m[k][j];
					}

			return result;
		}


	};
}