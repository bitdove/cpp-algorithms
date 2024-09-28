#!/bin/bash

# Create the build directory if it doesn't exist
if [ ! -d "build" ]; then
  mkdir build
fi

# Run CMake in the build directory
cd build
cmake ..

# Build the project using make
make

# Return to the project root directory
cd ..

# Inform the user where the executable can be found
echo "Build complete. Executable located in the ./bin directory."
