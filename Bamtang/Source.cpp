#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>

#include "spdlog/spdlog.h"

#include <map>
#include <string>

#include <iostream>
#include <sstream>
#include <fstream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Texture2D.h"
#include "Shader.h"
#include "Sprite.h"

//#include "Game.h"
#include "SceneAssets.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "GLFrameBuffer.h"

#include "WindowController.h"
#include "NatureController.h"

#include "Scene.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);




int main(int argc, char* argv[])
{
    
    NatureLab::Scene* scene = new NatureLab::Scene();

    scene->run();


    return 0;
}



void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

