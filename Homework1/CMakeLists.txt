cmake_minimum_required(VERSION 3.10)

set(porject_name Homework1)
project(${porject_name})

set(CMAKE_CXX_STANDARD 17)

# opencv
set(OpenCV_DIR "D:\\Software\\opencv\\build\\x64\\mingw\\install")
find_package(OpenCV REQUIRED)
# Eigen
include_directories("C:\\Program Files (x86)\\Eigen3\\include")
# head file
include_directories(./include)
# src file
aux_source_directory(./src SrcFiles)

add_executable(${porject_name} ${SrcFiles})

target_link_libraries(${porject_name} ${OpenCV_LIBRARIES})