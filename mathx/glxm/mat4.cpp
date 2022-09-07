#include "mat4.h"
#include <cmath>
#include <spdlog/spdlog.h>

namespace glxm
{
    mat4::mat4()
    {
        for (unsigned int i = 0; i < 4; i++)
            for (unsigned int j = 0; j < 4; j++)
                val[i][j] = 0.0f;
    }

    mat4::mat4(float value)
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

    mat4 mat4::identity()
    {
        const auto new_matrix = new mat4();
        for (int i = 0; i < 4; i++)
            new_matrix->val[i][i] = 1;
        return *new_matrix;
    }

    mat4 mat4::translate(mat4& transform, const float& dx, const float& dy, const float& dz)
    {
        transform.val[3][0] = dx;
        transform.val[3][1] = dy;
        transform.val[3][2] = dz;

        return transform;
    }

    mat4 mat4::scale(mat4& transform, const float& px, const float& py, const float& pz)
    {
        transform.val[0][0] = px;
        transform.val[1][1] = py;
        transform.val[2][2] = pz;

        return transform;
    }

    mat4 mat4::rotation_around_x(mat4 transform, const float& angle)
    {
        transform.val[1][1] = cos(angle);
        transform.val[1][2] = sin(angle);
        transform.val[2][1] = -sin(angle);
        transform.val[2][2] = cos(angle);

        return transform;
    }

    mat4 mat4::rotation_around_y(mat4 transform, const float& angle)
    {
        transform.val[0][0] = cos(angle);
        transform.val[0][2] = -sin(angle);
        transform.val[2][0] = sin(angle);
        transform.val[2][2] = cos(angle);

        return transform;
    }

    mat4 mat4::rotation_around_z(mat4 transform, const float& angle)
    {
        transform.val[0][0] = cos(angle);
        transform.val[0][1] = sin(angle);
        transform.val[1][0] = -sin(angle);
        transform.val[1][1] = cos(angle);

        return transform;
    }

    mat4 mat4::ortho(mat4 transform, float left, float right, float bottom, float top, float z_near, float z_far)
    {
        transform.val[0][0] = 2.0f / (right - left);
        transform.val[1][1] = 2.0f / (top - bottom);
        transform.val[2][2] = -2.0f / (z_far - z_near);

        transform.val[3][0] = -(right + left) / (right - left);
        transform.val[3][1] = -(top + bottom) / (top - bottom);
        transform.val[3][2] = -(z_far + z_near) / (z_far - z_near);

        return transform;
    }

    void mat4::printf(const mat4& value)
    {
        spdlog::info(
            "mat4-printf\n[{},{},{},{}]\n[{},{},{},{}]\n[{},{},{},{}]\n[{},{},{},{}]",
            value.val[0][0], value.val[0][1], value.val[0][2], value.val[0][3],
            value.val[1][0], value.val[1][1], value.val[1][2], value.val[1][3],
            value.val[2][0], value.val[2][1], value.val[2][2], value.val[2][3],
            value.val[3][0], value.val[3][1], value.val[3][2], value.val[3][3]
        );
    }
}
