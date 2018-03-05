cmake_minimum_required(VERSION 3.0)
project(my_lib)
set(CMAKE_CXX_STANDARD 14)


find_package(PkgConfig)
find_package(Threads)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

#You can specify the URL for google test, so that it uses a computer location
if (NOT DEFINED GOOGLE_TEST_URL)
    set(GOOGLE_TEST_URL http://pkgs.fedoraproject.org/repo/pkgs/gtest/gtest-1.7.0.zip/2d6ec8ccdf5c46b05ba54a9fd1d130d7/gtest-1.7.0.zip)
endif ()
#You can specify the URL for google mock, so that it uses a computer location
if (NOT DEFINED GOOGLE_MOCK_URL)
    set(GOOGLE_MOCK_URL https://github.com/paulsapps/gmock-1.7.0/archive/master.zip)
endif ()
include_directories(${CMAKE_SOURCE_DIR})
add_subdirectory(structures)
add_subdirectory(programas)


