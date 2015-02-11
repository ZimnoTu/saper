cmake_minimum_required(VERSION 2.8)

#find_package(boost)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "-g -std=c++11  -pedantic-errors")

add_subdirectory(src)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(tst)
