cmake_minimum_required(VERSION 3.23)
project(FriendFunctions)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(FriendFunctions main.cpp Point3d.cpp Point3d.h Vector3d.cpp Vector3d.h)
