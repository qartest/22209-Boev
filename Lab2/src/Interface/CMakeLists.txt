cmake_minimum_required(VERSION 2.8...3.13)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Interfaces)

add_library(Interfaces interface.cpp)