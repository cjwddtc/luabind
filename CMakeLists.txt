cmake_minimum_required(VERSION 3.8)
project(main)

set(CMAKE_CXX_STANDARD 17)
find_package(Boost REQUIRED)
include_directories(${BOOST_INCLUDE_DIR})
set(SOURCE_FILES main.cpp)
add_executable(ttt ${SOURCE_FILES})