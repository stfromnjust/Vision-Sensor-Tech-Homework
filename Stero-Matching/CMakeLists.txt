cmake_minimum_required(VERSION 3.20)
project(Stero_Matching)

set(CMAKE_CXX_STANDARD 14)

add_executable(Stero_Matching
#        stereo_matching.cpp
        Sad.h
        MySad.cpp)

find_package(OpenCV REQUIRED)
target_link_libraries(Stero_Matching ${OpenCV_LIBS})
