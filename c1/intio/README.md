This example demonstrates the definition and use of two
generic integer IO operations that read and write an integer
to a specified location.

This project has also been used to demonstrate the use of both
make and cmake in compiling C projects

Using make
----------

To build all binaries, run 'make all'.  The binaries will be
build locally

To clean anything required, run './clean_all'
This is a batch script that runs make's clean
rule and removes any other files necessary

Using cmake
-----------
The compilation process for using cmake is split into 2 steps.
CMake must first be initalized to trigger an out-of-source
build and then CMake should be used again to trigger the
build itself.

Run ./compile in order to perform both of these steps

As the compilation script provided triggers and out-of-source
build, the build artefacts can be removed by running
'rm -rf build'
