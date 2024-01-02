cmake_minimum_required(VERSION 2.8...3.13)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/answer)

project (Laba2)

include_directories(src)
add_subdirectory(src/Controller/)
add_subdirectory(src/Game/)
add_subdirectory(src/Interface/)
add_subdirectory(src/Example/)
add_subdirectory(src/Parser/)
add_subdirectory(src/Field/)



add_executable(Laba2 src/main.cpp)

target_link_libraries(Laba2 PUBLIC Parser  Controllers Games Interfaces Examples Field)

set(COVERAGE_DIR ${CMAKE_SOURCE_DIR}/answer)

