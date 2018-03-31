cmake_minimum_required(VERSION 3.0)
project(my_lib)
set(CMAKE_CXX_STANDARD 14)


# adding google test
find_package(PkgConfig)
find_package(Threads)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR})

#adding structures
add_subdirectory(structures)
include_directories(structures)

#adding eigen librar#Set static compilation for boost
find_package(Boost REQUIRED COMPONENTS system filesystem program_options)
pkg_check_modules(EIGEN3 REQUIRED eigen3)
include_directories(${EIGEN3_INCLUDE_DIRS})

#adding programs
add_subdirectory(programas)
include_directories(programas)
add_subdirectory(tests)



