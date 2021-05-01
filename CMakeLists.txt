cmake_minimum_required(VERSION 3.6)
project(fix_image)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES cal_image.cpp.cpp)

add_executable(opencv cal_image.cpp)

target_link_libraries(opencv ${OpenCV_LIBS})