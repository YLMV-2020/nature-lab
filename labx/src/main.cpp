#include "app/NatureLab.h"

int main(int argc, char* argv[])
{ 
    srand(time(NULL));
    labx::Scene* scene = new labx::Scene();
    return scene->run();
}
