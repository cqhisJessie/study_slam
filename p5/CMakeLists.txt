cmake_minimum_required( VERSION 2.8 )
project(ch3_practice5)

set(CMAKE_CXX_FLAGS "-std=c++11")

# 添加Eigen头文件
include_directories( "/usr/include/eigen3" )


add_executable( p5 p5.cpp)
set( CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/bin/")
install(TARGETS p5 RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX})
