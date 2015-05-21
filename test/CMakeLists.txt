set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -fPIC")

add_executable(test_main
    TestQuaternion.cpp
    TestVector3.cpp
    TestDegree.cpp
)

target_link_libraries(test_main
    math
    libgtest_main
    libgtest
)
