cmake_minimum_required(VERSION 3.16)

file(GLOB_RECURSE DLL
         RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
	   ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp 
         ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(physx SHARED ${DLL})