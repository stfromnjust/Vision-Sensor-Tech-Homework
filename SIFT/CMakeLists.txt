cmake_minimum_required(VERSION 3.19)
project(SIFT)

set(CMAKE_CXX_STANDARD 14)

add_executable(SIFT
        sift.cpp)

find_package(OpenCV REQUIRED)
target_link_libraries(SIFT ${OpenCV_LIBS})
