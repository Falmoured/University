cmake_minimum_required(VERSION 3.15)



set(PROJECT_NAME 8.1Lab)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("inc/")
include_directories("src/")


add_executable("${PROJECT_NAME}" 8.1Lab)

set(PROJECT_NAME 8.2Lab)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("inc/")
include_directories("src/")


add_executable("${PROJECT_NAME}" 8.2Lab)