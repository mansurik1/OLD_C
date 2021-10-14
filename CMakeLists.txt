cmake_minimum_required(VERSION 3.12.4)
project(Project)

set(CMAKE_C_STANDARD 11)

set(LIB_SOURCE_FILES library.c)
add_library(containers STATIC ${LIB_SOURCE_FILES})

add_executable(main main.c)
target_link_libraries(main containers)

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(main_test main_test.cpp)
target_link_libraries(main_test ${GTEST_LIBRARIES} containers pthread)
