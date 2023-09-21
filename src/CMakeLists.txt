# Create a library target for bar
add_library(bar
    bar/bar.cpp
    ../include/bar/bar.h
)

# Include directories for bar
target_include_directories(bar PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Create a library target for foo
add_library(foo
    foo/foo.cpp
    ../include/foo/foo.h
)

# Include directories for foo
target_include_directories(foo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
