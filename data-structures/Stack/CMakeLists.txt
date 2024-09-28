# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(StackProject VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Output executables to the 'bin' directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# Add the test executable
add_executable(test_Stack __test__/test_Stack.cpp)

# Link the LinkedList library to the test executable
target_link_libraries(test_Stack)
