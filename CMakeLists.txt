cmake_minimum_required(VERSION 3.16)
project(see)

set(CMAKE_CXX_STANDARD 17)

add_executable(see main.cpp PrimitiveDrawer.cpp PrimitiveDrawer.h Point.cpp Point.h texture.cpp texture.h)

target_link_libraries(see -lglew32 -lopengl32 -lfreeglut glu32)
