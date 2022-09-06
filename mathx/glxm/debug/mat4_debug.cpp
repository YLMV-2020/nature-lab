#include "mat4_debug.h"
#include <spdlog/spdlog.h>

namespace glxm
{
    void mat4_debug::printf(const mat4& value)
    {
        spdlog::info(
            "mat4-printf\n[{},{},{},{}]\n[{},{},{},{}]\n[{},{},{},{}]\n[{},{},{},{}]",
            value.m[0][0], value.m[0][1], value.m[0][2], value.m[0][3],
            value.m[1][0], value.m[1][1], value.m[1][2], value.m[1][3],
            value.m[2][0], value.m[2][1], value.m[2][2], value.m[2][3],
            value.m[3][0], value.m[3][1], value.m[3][2], value.m[3][3]
        );
    }
}
