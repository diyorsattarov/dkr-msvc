cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME microservice)
project(${PROJECT_NAME})

# Add the executable
add_executable(microservice microservice.cpp)

# Link libevent
find_package(Libevent REQUIRED)
target_link_libraries(microservice PRIVATE ${LIBEVENT_LIB})


# Find Boost libraries
# find_package(Boost 1.71.0 REQUIRED COMPONENTS system thread)

# Link Boost libraries
# target_link_libraries(service PRIVATE Boost::system Boost::thread)
