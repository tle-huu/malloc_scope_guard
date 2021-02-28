cmake_minimum_required(VERSION 3.10)

project(malloc_scope_guard VERSION 1.0.0 DESCRIPTION "malloc scope guard")

add_library(malloc_scope_guard SHARED
	my_malloc.cpp
	malloc_scope_guard.cpp
)
target_link_libraries(malloc_scope_guard dl)
set_target_properties(malloc_scope_guard PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(malloc_scope_guard PROPERTIES PUBLIC_HEADER malloc_scope_guard.hpp)

install(TARGETS malloc_scope_guard
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
