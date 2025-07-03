cmake_minimum_required(VERSION 3.31)
project(MathFor3DGraphics)

set(CMAKE_CXX_STANDARD 23)

add_executable(MathFor3DGraphics main.cpp
        Vector3D.cpp
        Vector3D.h
        Matrix3x3.cpp
        Matrix3x3.h)
