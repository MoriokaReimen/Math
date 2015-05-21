add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(bin)
add_subdirectory(include)
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_BINARY_DIR}/include" "/usr/include/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")
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
