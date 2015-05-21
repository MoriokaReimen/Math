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


###############################################################################
# include gtest
include(ExternalProject)
# Download and install GoogleTest
ExternalProject_Add(
    libgtest
    URL https://googletest.googlecode.com/files/gtest-1.7.0.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    # Disable install step
    INSTALL_COMMAND ""
)
## Create a libgtest target to be used as a dependency by test programs
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)
# Set gtest properties
ExternalProject_Get_Property(gtest source_dir binary_dir)
set_target_properties(libgtest PROPERTIES
    "IMPORTED_LOCATION" "bin/libgtest.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)
###############################################################################


# math Library
add_library(math STATIC
src/Degree.cpp include/Degree.hpp
src/Vector3.cpp include/Vector3.hpp
src/Quaternion.cpp include/Quaternion.hpp
)

# test codes
enable_testing()
add_executable(math_test
    test/test_main.cpp
    test/TestDegree.cpp
    test/TestVector3.cpp
    test/TestQuaternion.cpp
)
target_link_libraries(math_test math gtest pthread)
add_test(math_test ./bin/math_test)
