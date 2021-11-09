cmake_minimum_required(VERSION 3.12.4)
project(homework-2)
add_compile_options(-Wall -Werror -Wpedantic)

add_compile_options(-fno-omit-frame-pointer -fsanitize=address)
add_link_options(-fsanitize=address)
add_compile_options(--coverage)
add_link_options(--coverage)

enable_testing()
find_package(GTest REQUIRED)

set(STATIC_LIB_SOURCE_FILES static_library.c)
add_library(posts STATIC ${STATIC_LIB_SOURCE_FILES})

add_executable(main main.c)
target_link_libraries(main posts)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(static_library_test static_library_test.cpp)
target_link_libraries(static_library_test ${GTEST_LIBRARIES} posts pthread)
