cmake_minimum_required(VERSION 3.12)
project(ConnectFour)

set(CMAKE_CXX_STANDARD 11)

# find_package(Catch2 3 REQUIRED)
# # These tests can use the Catch2-provided main
# add_executable(tests test.cpp)
# target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# # These tests need their own main
# add_executable(custom-main-tests test.cpp test-main.cpp)
# target_link_libraries(custom-main-tests PRIVATE Catch2::Catch2)

# Add the executable
add_executable(ConnectFour
    src/main.cpp
    src/ConnectFour.cpp
    src/ConnectFour.h
)
