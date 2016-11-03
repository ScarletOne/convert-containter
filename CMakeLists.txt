cmake_minimum_required(VERSION 3.2)
project(convert-container)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(UT_LIBS_DIR UT/LIBS)
include_directories(${LIBS_DIR}/Catch)

set(TEST_FILES UT/convertUT.cpp)
add_executable(tests ${TEST_FILES})
