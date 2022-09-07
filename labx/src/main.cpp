#include "glxm/mat4.h"
#include "glxm/debug/mat4_debug.h"

int main(int argc, char* argv[])
{
    glxm::mat4 model = glxm::mat4(1.0f);
    model = glxm::mat4::identity();
    glxm::mat4::printf(model);
    const auto model2 = glxm::mat4::translate(model, 14, 6, 23);
    model = glxm::mat4::translate(model, 15, 66, 23);

    model = glxm::mat4::scale(model, 2.0f, 2.0f, 3.0f);

    glxm::mat4::printf(model*model2);
    return 0;
}
