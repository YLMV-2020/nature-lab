#include "NatureLab.h"

int main(int argc, char* argv[])
{ 
    srand(time(NULL));
    NatureLab::Scene* scene = new NatureLab::Scene();
    return scene->run();
}
