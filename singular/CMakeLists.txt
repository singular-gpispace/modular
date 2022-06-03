cmake_minimum_required(VERSION 3.15)
project(libsingular-call-cmake LANGUAGES C CXX)

add_executable(main src/main.cpp)
target_include_directories(main PUBLIC /opt/Singular430/Singular/include /opt/Singular430/Singular/include/singular)
target_link_directories(main PUBLIC /opt/Singular430/Singular/lib)
target_link_libraries(main Singular polys singular_resources factory omalloc dl)



