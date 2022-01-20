cmake_minimum_required(VERSION 3.15)



set(PROJECT_NAME Add_N5)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)



add_executable("${PROJECT_NAME}" 5.1Add.cpp 5.1Add_f.cpp 5.1Add_f.hpp)