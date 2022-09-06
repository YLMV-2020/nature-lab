#include "glxm/mat4.h"
#include "glxm/debug/mat4_debug.h"

int main(int argc, char* argv[])
{
    glxm::mat4 matrix{};
    matrix = glxm::mat4::identity();
    glxm::mat4_debug::printf(matrix);
    return 0;
}
