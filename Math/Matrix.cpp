#include "pch.h"
#include "Matrix.h"

namespace Math {

	Math::Matrix::Matrix()
	{
		for (unsigned int i = 0; i < 4; i++)
		{
			for (unsigned int j = 0; j < 4; j++)
				this->_m[i][j] = 0;
		}
	}

	Matrix::Matrix(int n)
	{
		for (unsigned int i = 0; i < 4; i++)
		{
			for (unsigned int j = 0; j < 4; j++)
				this->_m[i][j] = n;
		}
	}

	Matrix Matrix::identity()
	{
		Matrix* temp = new Matrix();
		for (int i = 0; i < 4; i++)
			temp->_m[i][i] = 1;

		return *temp;
	}

	Matrix Matrix::translate(Matrix transform, const Vector& v1)
	{
		transform._m[3][0] = v1.x;
		transform._m[3][1] = v1.y;
		transform._m[3][2] = v1.z;

		return transform;
	}

	Matrix Matrix::translate(Matrix transform, const int& dx, const int& dy, const int& dz)
	{
		transform._m[3][0] = dx;
		transform._m[3][1] = dy;
		transform._m[3][2] = dz;

		return transform;
	}

	Matrix Matrix::scale(Matrix transform, const Vector& v1)
	{
		transform._m[0][0] = v1.x;
		transform._m[1][1] = v1.y;
		transform._m[2][2] = v1.z;

		return transform;
	}

	Matrix Matrix::scale(Matrix transform, const int& px, const int& py, const int& pz)
	{
		transform._m[0][0] = px;
		transform._m[1][1] = py;
		transform._m[2][2] = pz;

		return transform;
	}

	Matrix Matrix::rotationAroundX(Matrix transform, const float& angle)
	{

		transform._m[1][1] = cos(angle);
		transform._m[1][2] = sin(angle);
		transform._m[2][1] = -sin(angle);
		transform._m[2][2] = cos(angle);

		return transform;
	}

	Matrix Matrix::rotationAroundY(Matrix transform, const float& angle)
	{

		transform._m[0][0] = cos(angle);
		transform._m[0][2] = -sin(angle);
		transform._m[2][0] = sin(angle);
		transform._m[2][2] = cos(angle);

		return transform;
	}

	Matrix Matrix::rotationAroundZ(Matrix transform, const float& angle)
	{

		transform._m[0][0] = cos(angle);
		transform._m[0][1] = sin(angle);
		transform._m[1][0] = -sin(angle);
		transform._m[1][1] = cos(angle);

		return transform;
	}

	//Matrix Matrix::rotation(float x, float y, float z)
	//{
	//	//return Matrix::rotationAroundZ(z) * Matrix::rotationAroundX(x) * Matrix::rotationAroundY(y);
	//}

	Matrix Matrix::ortho(Matrix transform, float left, float right, float bottom, float top, float zNear, float zFar)
	{
		transform._m[0][0] = 2.0f / (right - left);
		transform._m[1][1] = 2.0f / (top - bottom);
		transform._m[2][2] = -2.0f / (zFar - zNear);

		transform._m[3][0] = -(right + left) / (right - left);
		transform._m[3][1] = -(top + bottom) / (top - bottom);
		transform._m[3][2] = -(zFar + zNear) / (zFar - zNear);

		return transform;

	}

	Vector Matrix::getPosition(Matrix& transform)
	{
		return Vector(transform._m[3][0], transform._m[3][1], transform._m[3][2]);
	}

	Vector Matrix::getScale(Matrix& transform)
	{
		return Vector(transform._m[0][0], transform._m[1][1], transform._m[2][2]);
	}

	/*void Matrix::pushMatrix(const Matrix& transform)
	{
		Matrix::transformations.push(transform);
	}
	Matrix Matrix::popMatrix()
	{
		Math::Matrix m = Math::Matrix();
		m.identity();
		while (!Matrix::transformations.empty())
		{
			m = m * Matrix::transformations.front();
			Matrix::transformations.pop();
		}
		return m;
	}*/
}