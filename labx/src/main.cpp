#include "nature_lab.h"
#include "glxm\vec2.h"
int main(int argc, char* argv[])
{
	srand(time(NULL));
	const nature_lab::scene* scene = new nature_lab::scene();
	return scene->run();
}
