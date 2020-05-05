cmake_minimum_required(VERSION 3.0)

project(intio)

add_library(
    intio
    intio.c
)

add_executable(
    intiotest
    test.c
)

target_link_libraries(
    intiotest
    PRIVATE
    intio
)
