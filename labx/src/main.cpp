#include "app/nature_lab.h"

int main(int argc, char* argv[])
{ 
    srand(time(NULL));
    nature_lab::Scene* scene = new nature_lab::Scene();
    return scene->run();
}
