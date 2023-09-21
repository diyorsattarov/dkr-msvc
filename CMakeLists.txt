cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME cpp-cmake-template)

project(${PROJECT_NAME})

add_subdirectory(src)

# Include directories for your project
include_directories(include)

set(SOURCES
    src/bar/bar.cpp
    src/foo/foo.cpp
)

add_executable(${PROJECT_NAME} 
    ${SOURCES}
    examples/bar/example_bar.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE src include examples)

add_executable(tests
    ${SOURCES}
    tests/bar/test_bar.cpp
    tests/foo/test_foo.cpp
)

find_package(GTest REQUIRED)
target_include_directories(tests PRIVATE ${GTEST_INCLUDE_DIRS})

target_link_libraries(tests PRIVATE ${GTEST_BOTH_LIBRARIES} pthread)

add_custom_target(run_tests COMMAND tests)