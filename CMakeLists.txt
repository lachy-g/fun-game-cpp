cmake_minimum_required(VERSION 3.13)

# set the project name and version
project(SimpleGame VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(simpleGame ${SOURCES})
