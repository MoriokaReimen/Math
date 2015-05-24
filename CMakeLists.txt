cmake_minimum_required(VERSION 2.8)
add_subdirectory(include)
add_subdirectory(src)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")

INCLUDE_DIRECTORIES("${CMAKE_CURRENT_BINARY_DIR}/include" "/usr/include/")


project(math)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -fPIC")
# math Library
add_library(math STATIC
src/Degree.cpp include/Degree.hpp
src/Vector3.cpp include/Vector3.hpp
src/Quaternion.cpp include/Quaternion.hpp
)

target_include_directories(math PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/include
)


enable_testing()
add_subdirectory(test)
