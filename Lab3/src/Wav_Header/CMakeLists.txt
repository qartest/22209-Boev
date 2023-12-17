cmake_minimum_required(VERSION 2.8...3.13)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBRARY_NAME CheckWav)

add_library(${LIBRARY_NAME} STATIC)

target_link_libraries(${LIBRARY_NAME} PUBLIC Stream)
target_link_libraries(${LIBRARY_NAME} PUBLIC wav_hdr)
target_link_libraries(${LIBRARY_NAME} PUBLIC OneSecond)
target_include_directories(${LIBRARY_NAME} PUBLIC include)

target_sources(${LIBRARY_NAME}
    PUBLIC
        include/CheckWav.hpp
        include/ErrorsWav.hpp
    PRIVATE
        src/CheckWav.cpp)
