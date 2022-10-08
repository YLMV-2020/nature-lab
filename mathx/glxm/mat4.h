#pragma once
#include <cmath>
#include "vec2.h"
#include "vec3.h"

namespace glxm
{
    class mat4
    {
    public:
        mat4()
        {
            for (unsigned int i = 0; i < 4; i++)
                for (unsigned int j = 0; j < 4; j++)
                    val[i][j] = 0.0f;
        }

        explicit mat4(const float value)
        {
            for (unsigned int i = 0; i < 4; i++)
            {
                for (unsigned int j = 0; j < 4; j++)
                {
                    if (i == j)
                        val[i][j] = value;
                    else
                        val[i][j] = 0.0f;
                }
            }
        }

        static mat4 identity()
        {
            const auto new_matrix = new mat4();
            for (int i = 0; i < 4; i++)
                new_matrix->val[i][i] = 1;

            return *new_matrix;
        }

        friend mat4 operator*(const mat4& m1, const mat4& m2)
        {
            mat4 result = mat4();
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    for (int k = 0; k < 4; k++)
                    {
                        result(i, j) += m1.val[i][k] * m2.val[k][j];
                    }

            return result;
        }

        float& mat4::operator()(const int r, const int c)
        {
            return val[r][c];
        }

        //private:
        float val[4][4]{};
    };


    static void printf(const mat4& value)
    {
        std::cout << "mat4\n";
        std::cout << "[" << value.val[0][0] << "][" << value.val[0][1] << "][" << value.val[0][2] << "][" << value.val[
            0][3] << "]\n";
        std::cout << "[" << value.val[1][0] << "][" << value.val[1][1] << "][" << value.val[1][2] << "][" << value.val[
            1][3] << "]\n";
        std::cout << "[" << value.val[2][0] << "][" << value.val[2][1] << "][" << value.val[2][2] << "][" << value.val[
            2][3] << "]\n";
        std::cout << "[" << value.val[3][0] << "][" << value.val[3][1] << "][" << value.val[3][2] << "][" << value.val[
            3][3] << "]\n";
    }

    static mat4 translate(mat4& transform, const float& dx, const float& dy, const float& dz)
    {
        transform.val[3][0] = dx;
        transform.val[3][1] = dy;
        transform.val[3][2] = dz;

        return transform;
    }

    static mat4 translate(mat4& transform, const vec2& v1)
    {
        transform(3, 0) = v1.x;
        transform(3, 1) = v1.y;
        transform(3, 2) = 0.0f;

        return transform;
    }

    static mat4 translate(mat4& transform, const vec3& v1)
    {
        transform.val[3][0] = v1.x;
        transform.val[3][1] = v1.y;
        transform.val[3][2] = v1.z;

        return transform;
    }

    static mat4 scale(mat4& transform, const float& px, const float& py, const float& pz)
    {
        transform.val[0][0] = px;
        transform.val[1][1] = py;
        transform.val[2][2] = pz;

        return transform;
    }

    static mat4 scale(mat4& transform, const vec2& v1)
    {
        transform(0, 0) = v1.x;
        transform(1, 1) = v1.y;
        transform(2, 2) = 1.0f;

        return transform;
    }

    static mat4 scale(mat4& transform, const vec3& v1)
    {
        transform.val[0][0] = v1.x;
        transform.val[1][1] = v1.y;
        transform.val[2][2] = v1.z;

        return transform;
    }

    static mat4 rotate_x(mat4& transform, const float& angle)
    {
        transform.val[1][1] = cos(angle);
        transform.val[1][2] = sin(angle);
        transform.val[2][1] = -sin(angle);
        transform.val[2][2] = cos(angle);

        return transform;
    }

    static mat4 rotate_y(mat4& transform, const float& angle)
    {
        transform.val[0][0] = cos(angle);
        transform.val[0][2] = -sin(angle);
        transform.val[2][0] = sin(angle);
        transform.val[2][2] = cos(angle);

        return transform;
    }

    static mat4 rotate_z(mat4& transform, const float& angle)
    {
        transform.val[0][0] = cos(angle);
        transform.val[0][1] = sin(angle);
        transform.val[1][0] = -sin(angle);
        transform.val[1][1] = cos(angle);

        return transform;
    }

    static mat4 ortho(mat4& transform, const float left, const float right, const float bottom, const float top,
                      const float z_near, const float z_far)
    {
        transform.val[0][0] = 2.0f / (right - left);
        transform.val[1][1] = 2.0f / (top - bottom);
        transform.val[2][2] = -2.0f / (z_far - z_near);

        transform.val[3][0] = -(right + left) / (right - left);
        transform.val[3][1] = -(top + bottom) / (top - bottom);
        transform.val[3][2] = -(z_far + z_near) / (z_far - z_near);

        return transform;
    }
}
