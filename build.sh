#!/bin/bash
echo "Buidling the code.."
echo "1. Removing the old build..."
if [ -d build ]; then rm -Rf build; fi
echo "2. Creating the build and building..."
cmake -S . -B build
cmake --build build
