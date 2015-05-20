cmake_minimum_required(VERSION 2.8)
project(Math)
add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(bin)
add_subdirectory(include)
add_subdirectory(test)
INCLUDE_DIRECTORIES("${CMAKE_BINARY_DIR}/include" "/usr/include/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -fPIC")

# math Library
add_library(math STATIC
src/Degree.cpp include/Degree.hpp
src/Vector3.cpp include/Vector3.hpp 
src/Quaternion.cpp include/Quaternion.hpp 
)

# test codes
enable_testing()
add_executable(math_test
    test/TestDegree.cpp
    test/TestVector3.cpp
)
target_link_libraries(math_test math gtest gtest_main pthread)
add_test(math_test ./bin/math_test)
