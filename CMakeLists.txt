cmake_minimum_required(VERSION 3.16)

SET(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(physxdev)

file(GLOB_RECURSE MAIN
         RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
         ${CMAKE_CURRENT_SOURCE_DIR}/labx/src/*.cpp 
         ${CMAKE_CURRENT_SOURCE_DIR}/labx/src/*.h)

file(GLOB_RECURSE ASSETS  
    ${CMAKE_CURRENT_SOURCE_DIR}/labx/assets/shaders/*
)

source_group("assets" FILES ${ASSETS})

add_subdirectory(mathx)

find_path(STB_INCLUDE_DIRS "stb.h")

find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(imguizmo CONFIG REQUIRED)

add_executable(${PROJECT_NAME} ${MAIN})

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE GLEW::GLEW)
target_link_libraries(${PROJECT_NAME} PRIVATE imgui::imgui)
target_link_libraries(${PROJECT_NAME} PRIVATE imguizmo::imguizmo)

target_link_libraries(${PROJECT_NAME} PUBLIC mathx)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/mathx)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

set_target_properties(mathx PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/labx/assets
                ${CMAKE_CURRENT_BINARY_DIR}/assets)

                
target_sources(${PROJECT_NAME} PRIVATE ${ASSETS})
