cmake_minimum_required(VERSION 3.16)

file(GLOB_RECURSE DLL
         RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
	   ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp 
         ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

find_package(spdlog CONFIG REQUIRED)

add_library(mathx SHARED ${DLL})

target_link_libraries(mathx PRIVATE spdlog::spdlog spdlog::spdlog_header_only)