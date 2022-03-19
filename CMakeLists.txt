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
add_library(posts_static STATIC ${STATIC_LIB_SOURCE_FILES})

set(SHARED_LIB_SOURCE_FILES shared_library.c)
add_library(posts_shared SHARED ${SHARED_LIB_SOURCE_FILES})

add_executable(main main.c)

option(WITH_PARALLEL "Using shared library" ON)
if(WITH_PARALLEL)
    target_link_libraries(main posts_shared)
else()
    target_link_libraries(main posts_static)
endif()

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(static_library_test static_library_test.cpp)
add_executable(shared_library_test shared_library_test.cpp)

target_link_libraries(static_library_test ${GTEST_LIBRARIES} posts_static pthread)
target_link_libraries(shared_library_test ${GTEST_LIBRARIES} posts_shared pthread)
