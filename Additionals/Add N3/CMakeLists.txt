cmake_minimum_required(VERSION 3.15)



set(PROJECT_NAME Add_N3)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)



add_executable("${PROJECT_NAME}" 3.1Add.cpp 3.1Add_func.cpp 3.1Add_func.hpp)