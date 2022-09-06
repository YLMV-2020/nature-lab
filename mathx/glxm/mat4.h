#pragma once

namespace glxm
{
    typedef float T;

    //template <class T>
    class __declspec(dllexport) mat4
    {
    public:
        T m[4][4];
        mat4();
    	static mat4 identity();
        /*static mat4 translate(mat4 transform, const T& dx, const T& dy, const T& dz);
        static mat4 scale(mat4 transform, const T& px, const T& py, const T& pz);
        static mat4 rotation_around_x(mat4 transform, const T& angle);
        static mat4 rotation_around_y(mat4 transform, const T& angle);
        static mat4 rotation_around_z(mat4 transform, const T& angle);
        static mat4 ortho(mat4 transform, T left, T right, T bottom, T top, T z_near, T z_far);*/

        friend mat4 operator*(const mat4& m1, const mat4& m2)
        {
        	mat4 result = mat4();
        	mat4::identity();
        
        	for (int i = 0; i < 4; i++)
        		for (int j = 0; j < 4; j++)
        			for (int k = 0; k < 4; k++)
        			{
        				result.m[i][j] += m1.m[i][k] * m2.m[k][j];
        			}
        
        	return result;
        }
    };
}
