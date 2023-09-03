cmake_minimum_required(VERSION 3.0)
project(SIMPLE_HTTP_SERVER)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(${CMAKE_SOURCE_DIR}/include)


# Ensure your project can find the Google Test headers
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_executable(SIMPLE_HTTP_SERVER src/main.cpp src/web_server.cpp)


