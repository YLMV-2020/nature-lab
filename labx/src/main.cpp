#include "nature_lab.h"

int main(int argc, char* argv[])
{
    srand(time(NULL));
    return nature_lab::scene().run();
}
