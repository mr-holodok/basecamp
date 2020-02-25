cmake_minimum_required(VERSION 3.13)
project(BucketSort)

set(CMAKE_CXX_STANDARD 17)

add_executable(BucketSort main.cpp BucketSorter.cpp BucketSorter.h)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../googletest ${CMAKE_CURRENT_BINARY_DIR}/googletest)
include_directories(${gTest_SOURCE_DIR}/include ${gTest_SOURCE_DIR})
add_executable(test test.cpp BucketSorter.cpp BucketSorter.h)
target_link_libraries(test gtest gtest_main)