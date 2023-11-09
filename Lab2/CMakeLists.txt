cmake_minimum_required(VERSION 2.8...3.13)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (Laba2)

include_directories(src)
add_subdirectory(src/Controller/)
add_subdirectory(src/Game/)
add_subdirectory(src/Interface/)
add_subdirectory(src/Example/)

set(SOURCE_FILES src/main.cpp)

add_executable(Laba2 ${SOURCE_FILES})

target_link_libraries(Laba2 PUBLIC Controllers Games Interfaces Examples)

