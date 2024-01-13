cmake_minimum_required(VERSION 3.22)
project(checkpass)
add_library(checkpass STATIC pass.cpp)
target_link_libraries(checkpass PRIVATE -lpam)