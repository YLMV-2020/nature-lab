#include "pch.h"
#include "Matrix.h"

namespace Math {

	Math::Matrix::Matrix()
	{
		for (unsigned int i = 0; i < 4; i++)
			for (unsigned int j = 0; j < 4; j++)			
				this->matrix[i][j] = 0;
	}

	Matrix Matrix::identity()
	{
		Matrix* temp = new Matrix();
		for (int i = 0; i < 4; i++)
			temp->matrix[i][i] = 1;

		return *temp;
	}

	Matrix Matrix::translate(Matrix transform, const Vector& v1)
	{
		transform.matrix[3][0] = v1.x;
		transform.matrix[3][1] = v1.y;
		transform.matrix[3][2] = v1.z;

		return transform;
	}

	Matrix Matrix::translate(Matrix transform, const int& dx, const int& dy, const int& dz)
	{
		transform.matrix[3][0] = dx;
		transform.matrix[3][1] = dy;
		transform.matrix[3][2] = dz;

		return transform;
	}

	Matrix Matrix::scale(Matrix transform, const Vector& v1)
	{
		transform.matrix[0][0] = v1.x;
		transform.matrix[1][1] = v1.y;
		transform.matrix[2][2] = v1.z;

		return transform;
	}

	Matrix Matrix::scale(Matrix transform, const int& px, const int& py, const int& pz)
	{
		transform.matrix[0][0] = px;
		transform.matrix[1][1] = py;
		transform.matrix[2][2] = pz;

		return transform;
	}

	Vector Matrix::getPosition(Matrix& transform)
	{
		return Vector(transform.matrix[3][0], transform.matrix[3][1], transform.matrix[3][2]);
	}

	Vector Matrix::getScale(Matrix& transform)
	{
		return Vector(transform.matrix[0][0], transform.matrix[1][1], transform.matrix[2][2]);
	}
}