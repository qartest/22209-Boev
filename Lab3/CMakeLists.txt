cmake_minimum_required(VERSION 2.8...3.13)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(SoundProcessor)

set(${PROJECT_NAME} SoundProcessor)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PUBLIC src/main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC ConventersLib FactoryLib Open Errors Controller CheckWav OneSecond Stream wav_hdr)

add_subdirectory(src/Conventers)
add_subdirectory(src/Factory)
add_subdirectory(src/Controller)
add_subdirectory(src/Open)
add_subdirectory(src/Errors)
add_subdirectory(src/Wav_Header)
add_subdirectory(src/OneSecond)
add_subdirectory(src/Stream)
add_subdirectory(src/wav_hdr)
