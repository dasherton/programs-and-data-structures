cmake_minimum_required(VERSION 3.0)

project(intio)

set(intio_lib_name intio)
set(intio_static_lib_name ${intio_lib_name}static)
set(test_exec_name intiotest)
set(intcpy_exec_name intcpy)
set(intcpy_shared_exec_name ${intcpy_exec_name}_)

###################
# Compile libraries
###################

add_library(
    ${intio_static_lib_name} STATIC
    intio.c
)

add_library(
    ${intio_lib_name} SHARED
    intio.c
)

#####################
# Compile test binary
#####################

add_executable(
    ${test_exec_name}
    test.c
)

target_link_libraries(
    ${test_exec_name}
    PRIVATE
    ${intio_lib_name}
)

#################################
# Compile intcpy using static lib
#################################

add_executable(
    ${intcpy_exec_name}
    intcpy.c
)

target_link_libraries(
    ${intcpy_exec_name}
    PRIVATE
    ${intio_static_lib_name}
)

#################################
# Compile intcpy using shared lib
#################################

add_executable(
    ${intcpy_shared_exec_name}
    intcpy.c
)

target_link_libraries(
    ${intcpy_shared_exec_name}
    PRIVATE
    ${intio_lib_name}
)
