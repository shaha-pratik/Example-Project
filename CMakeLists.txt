cmake_minimum_required(VERSION 3.14)
set(This Calculator)
set(ThisTest CalculatorTests)
project(${This} CXX)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

# Adding the library folder
add_subdirectory(src)

# Adding the executable for program
add_executable(${This} main.cpp)
target_link_libraries(${This} calculator)

# Starting the testing framework
enable_testing()

## Feching the googletest
## Using the local repository
# add_subdirectory(third_party/googletest)
## Using the fetch mechanism in cmake from github
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Creating the test executable
set(Sources
    test/calculator_test.cpp
)
add_executable(${ThisTest} ${Sources})

target_link_libraries(${ThisTest}
  gtest_main
  calculator
)

include(GoogleTest)
gtest_discover_tests(${ThisTest})
