cmake_minimum_required(VERSION 3.14)

project(Lab0)

set (CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES src/main.cpp)

add_executable(Lab0 ${SOURCE_FILES})

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
