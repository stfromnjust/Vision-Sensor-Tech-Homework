cmake_minimum_required(VERSION 3.17)
project(Image_Correction)

set(CMAKE_CXX_STANDARD 11)

add_executable(Image_Correction
        perspective_trans.cpp)

set(OpenCV_DIR D:/OpenCV-MinGW-Build-OpenCV-4.1.1-x64)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Image_Correction ${OpenCV_LIBS})
