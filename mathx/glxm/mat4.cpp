#include "mat4.h"
#include <cmath>

namespace glxm
{
	//template <typename T>
	mat4::mat4()
	{
		for (unsigned int i = 0; i < 4; i++)
		{
			for (unsigned int j = 0; j < 4; j++)
				this->m[i][j] = 0;
		}
	}

	//template <typename T>
	mat4 mat4::identity()
	{
		mat4* temp = new mat4();
		for (int i = 0; i < 4; i++)
			temp->m[i][i] = 1;

		

		return *temp;
	}

	//template <typename T>
   /* mat4<T> mat4<T>::translate(mat4 transform, const T& dx, const T& dy, const T& dz)
	{
		transform.m[3][0] = dx;
		transform.m[3][1] = dy;
		transform.m[3][2] = dz;

		return transform;
	}

	template <typename T>
	mat4<T> mat4<T>::scale(mat4 transform, const T& px, const T& py, const T& pz)
	{
		transform.m[0][0] = px;
		transform.m[1][1] = py;
		transform.m[2][2] = pz;

		return transform;
	}

	template <typename T>
	mat4<T> mat4<T>::rotation_around_x(mat4 transform, const T& angle)
	{
		transform.m[1][1] = cos(angle);
		transform.m[1][2] = sin(angle);
		transform.m[2][1] = -sin(angle);
		transform.m[2][2] = cos(angle);

		return transform;
	}

	template <typename T>
	mat4<T> mat4<T>::rotation_around_y(mat4 transform, const T& angle)
	{
		transform.m[0][0] = cos(angle);
		transform.m[0][2] = -sin(angle);
		transform.m[2][0] = sin(angle);
		transform.m[2][2] = cos(angle);

		return transform;
	}

	template <typename T>
	mat4<T> mat4<T>::rotation_around_z(mat4 transform, const T& angle)
	{
		transform.m[0][0] = cos(angle);
		transform.m[0][1] = sin(angle);
		transform.m[1][0] = -sin(angle);
		transform.m[1][1] = cos(angle);

		return transform;
	}

	template <typename T>
	mat4<T> mat4<T>::ortho(mat4 transform, T left, T right, T bottom, T top, T z_near, T z_far)
	{
		transform.m[0][0] = 2.0f / (right - left);
		transform.m[1][1] = 2.0f / (top - bottom);
		transform.m[2][2] = -2.0f / (z_far - z_near);

		transform.m[3][0] = -(right + left) / (right - left);
		transform.m[3][1] = -(top + bottom) / (top - bottom);
		transform.m[3][2] = -(z_far + z_near) / (z_far - z_near);

		return transform;
	}*/
}
