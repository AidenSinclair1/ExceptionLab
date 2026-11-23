cmake_minimum_required(VERSION 3.16)
project(ExceptionLab)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(ExceptionLab
    main.cpp
    Exceptions.cpp
    FileUtils.cpp
    GeometryUtils.cpp
)
