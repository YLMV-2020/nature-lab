enum laboratory { vector_n1, vector_n2 };

#include "nature_lab.h"

int main(int argc, char* argv[])
{
    srand(time(NULL));
    return nature_lab::scene().run(laboratory::vector_n1);
}
