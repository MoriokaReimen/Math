cmake_minimum_required(VERSION 2.8)
add_subdirectory(include)
add_subdirectory(src)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")

INCLUDE_DIRECTORIES("${CMAKE_CURRENT_BINARY_DIR}/include" "/usr/include/")


project(Math3D)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -fPIC")
# math Library
add_library(math3d_static STATIC
src/Degree.cpp include/Degree.hpp
src/Vector3.cpp include/Vector3.hpp
src/Quaternion.cpp include/Quaternion.hpp
)

target_include_directories(math3d_static PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/include
)


enable_testing()
add_subdirectory(test)

# doxygen config
find_package(Doxygen)
if(DOXYGEN_FOUND)
    add_custom_target(doc
        COMMAND doxygen Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generation documentation with doxygen" VERBATIM)
endif(DOXYGEN_FOUND)

# cpack config
install(TARGETS math3d_static
    RUNTIME DESTINATION "local/bin"
    LIBRARY DESTINATION "local/lib"
    ARCHIVE DESTINATION "local/lib")

install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/ DESTINATION "local/include/Math3D"
    FILES_MATCHING PATTERN "*.hpp")

set(CPACK_OUTPUT_FILE_PREFIX "packages")
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "MoriokaReimen")
include(CPack)
