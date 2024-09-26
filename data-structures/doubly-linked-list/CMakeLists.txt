# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(DoublyLinkedListProject VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Output executables to the 'bin' directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# Add the main library (DoublyLinkedList)
add_library(DoublyLinkedList src/DoublyLinkedList.cpp)

# Add the test executable
add_executable(test_doublylinkedlist __test__/test_DoublyLinkedList.cpp)

# Link the DoublyLinkedList library to the test executable
target_link_libraries(test_doublylinkedlist DoublyLinkedList)
