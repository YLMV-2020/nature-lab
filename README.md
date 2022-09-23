# [Labsxdev](https://github.com/devgrids/labsxdev)

## Summary
World physics simulator from scratch, applying the formulas and laws of physics

## Getting Started
Labsxdev has a single dependency: [cmake](http://www.cmake.org/download/), which is used to generate platform-specific makefiles or project files. Start by cloning this repository, making sure to pass the `--recursive` flag to grab all the dependencies. 

```bash
git clone --recursive https://github.com/devgrids/labsxdev
cd labsxdev
```
or
```bash
git clone https://github.com/devgrids/labsxdev
cd labsxdev
git submodule update --init --recursive
```
Now configure vcpkg, a Microsoft library that allows you to add external library dependencies in a very simple way.

```bash
.\vcpkg\bootstrap-vcpkg.bat
```
Install the following libraries with vcpkg:

```bash
.\vcpkg\vcpkg install glew:x64-windows
.\vcpkg\vcpkg install glfw3:x64-windows
.\vcpkg\vcpkg install imgui[core,glfw-binding,opengl3-binding,docking-experimental]:x64-windows
.\vcpkg\vcpkg install imguizmo:x64-windows
```

## Dependencies

 Library                                                |Functionality           |
 ------------------------------------------------------ |----------------------- |
 [glew](https://github.com/nigels-com/glew)             |OpenGL Function Loader  |
 [glfw](https://github.com/glfw/glfw)                   |Windowing and Input     |
 [imgui](https://github.com/ocornut/imgui)              |Graphical User Interface|
 [imguizmo](https://github.com/CedricGuillemet/ImGuizmo)|Gizmo Manipulate        |

## Build

Now generate a project file or makefile for your platform. If you want to use a particular IDE, make sure it is installed; don't forget to set the Start-Up Project in Visual Studio or the Target in Xcode.

```bash
# UNIX Makefile
cmake ..

# Mac OSX
cmake -G "Xcode" ..

# Microsoft Windows
cmake -G "Visual Studio 17 2022" -B "build"
```
