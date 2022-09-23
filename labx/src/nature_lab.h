#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "spdlog/spdlog.h"

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

#include "opengl/Line.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "glxm/math.h"
#include "glxm/vec2.h"
#include "glxm/mat4.h"

#include "interfaces/interface_controller.h"
#include "controllers/nature_controller.h"
#include "controllers/gui_controller.h"
#include "controllers/window_controller.h"

#include "resource.h"
#include "app/Scene.h"