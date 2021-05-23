cmake_minimum_required(VERSION 3.19)
project(SIFT)

set(CMAKE_CXX_STANDARD 14)

add_executable(SIFT
        test.cpp)

find_package(opencv REQUIRED)
target_link_libraries(SIFT ${OpenCV_LIBS})
