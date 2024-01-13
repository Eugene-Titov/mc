cmake_minimum_required(VERSION 3.22)
project(pass)

find_library(PAM_LIB libpam.so REQUIRED)
if(NOT PAM_LIB)
    message(FATAL_ERROR "PAM library was not found")
endif ()


add_subdirectory(checkpass)

add_executable(check check.cpp)
target_link_libraries(check PRIVATE checkpass)
target_include_directories(check PRIVATE checkpass)
