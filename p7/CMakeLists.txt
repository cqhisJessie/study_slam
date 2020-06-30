cmake_minimum_required(VERSION 2.6)
project(practice7)

include_directories("/usr/include/eigen3")

add_executable(practice7 p7.cpp)
set( CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/bin/")
install(TARGETS practice7 RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX})

