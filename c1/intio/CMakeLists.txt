cmake_minimum_required(VERSION 3.0)

project(intio)

set(intio_lib_name intio)

add_library(
    ${intio_lib_name}
    intio.c
)

add_executable(
    intiotest
    test.c
)

target_link_libraries(
    intiotest
    PRIVATE
    ${intio_lib_name}
)
