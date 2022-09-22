#include "nature_lab.h"
#include "glxp/object.h"

int main(int argc, char* argv[])
{
    glxp::object o = glxp::object();

    srand(time(NULL));
    const nature_lab::scene* scene = new nature_lab::scene();
    return scene->run();
}
