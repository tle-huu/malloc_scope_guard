cmake_minimum_required(VERSION 3.10)

project(malloc_guard_test VERSION 1.0.0 DESCRIPTION "malloc scope guard test")

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)

set(CMAKE_LINK_WHAT_YOU_USE off)

add_executable(malloc_guard_test main.cpp)
target_link_libraries(malloc_guard_test PUBLIC  pthread malloc_scope_guard)

target_include_directories(malloc_guard_test PUBLIC
                            "${PROECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/lib"
                            )

add_compile_definitions($<$<STREQUAL:"${CMAKE_BUILD_TYPE}","Debug">:DEBUG>)

