cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME cpp-cmake-template)

project(${PROJECT_NAME})
add_subdirectory(src)

# Assuming you have a tests directory with test sources
add_executable(tests
    # ... other test files ...
    tests/bar/test_bar.cpp
)

find_package(GTest REQUIRED)

target_include_directories(tests PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(tests PRIVATE
    ${GTEST_BOTH_LIBRARIES} 
    pthread 
    bar
)

add_custom_target(run_tests COMMAND tests)
