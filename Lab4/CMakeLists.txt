cmake_minimum_required(VERSION 2.8...3.13)

set(CMAKE_CXX_CONPILER "g++")
set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)

project (templates)

set(${PROJECT_NAME} templates)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PUBLIC src/main.cpp src/DataError.hpp src/OutputTuple.hpp)


