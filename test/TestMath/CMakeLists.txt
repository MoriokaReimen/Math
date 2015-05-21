set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -fPIC")
add_executable(test_math
    test_main.cpp
    TestQuaternion.cpp
    TestVector3.cpp
    TestDegree.cpp
)
target_link_libraries(test_math
    math
    libgtest
    libgtest_main
    pthread
)
