#pragma once
#include "vec2.h"

namespace glxm
{
    class __declspec(dllexport) mat4
    {
    public:
        mat4();
        mat4(float value);
        static mat4 identity();
        static mat4 translate(mat4& transform, const float& dx, const float& dy, const float& dz);
        static mat4 translate(mat4& transform, const vec2& v1);
        static mat4 scale(mat4& transform, const float& px, const float& py, const float& pz);
        static mat4 scale(mat4 transform, const vec2& v1);
        static mat4 rotation_around_x(mat4 transform, const float& angle);
        static mat4 rotation_around_y(mat4 transform, const float& angle);
        static mat4 rotation_around_z(mat4 transform, const float& angle);
        static mat4 ortho(mat4 transform, float left, float right, float bottom, float top, float z_near, float z_far);

        friend mat4 operator*(const mat4& m1, const mat4& m2)
        {
            mat4 result = mat4::identity();
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    for (int k = 0; k < 4; k++)
                    {
                        result.val[i][j] += m1.val[i][k] * m2.val[k][j];
                    }
            return result;
        }


        // -------------------------------------------------------------------------------
        //									DEBUG
        // -------------------------------------------------------------------------------

        static void printf(const mat4& value);

    private:
        float val[4][4];
    };
}
