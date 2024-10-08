cmake_minimum_required(VERSION 2.8...3.13)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

project(second)

file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/answer)

include_directories(src)
add_subdirectory(src/Tests)
add_subdirectory(src/CircularBuffer)
add_subdirectory(googletest)

add_executable(Tests src/Tests/tests.cpp)

target_link_libraries(Tests CircularBuffer gtest gcov)

enable_testing()
add_test(TestCircularBuffer Tests)

set(COVERAGE_DIR ${CMAKE_SOURCE_DIR}/answer)

#add_custom_target(coverage
  #  COMMAND ${CMAKE_MAKE_PROGRAM} test
   # WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    #COMMAND gcov -o ${COVERAGE_DIR} ${CMAKE_SOURCE_DIR}/*.cpp
    #COMMENT "Running gcov"
#)

add_custom_target(coverage
    COMMAND ${CMAKE_MAKE_PROGRAM} test
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND lcov --capture --directory . --output-file ${COVERAGE_DIR}/coverage.info
    COMMAND lcov --remove ${COVERAGE_DIR}/coverage.info '/usr/include/*' --output-file ${COVERAGE_DIR}/coverage.info
    COMMAND genhtml ${COVERAGE_DIR}/coverage.info --output-directory ${COVERAGE_DIR}/html
    COMMENT "Running gcov and lcov"
)
