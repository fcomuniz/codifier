#You can specify the URL for google test, so that it uses a computer location
if (NOT DEFINED GOOGLE_TEST_URL)
    set(GOOGLE_TEST_URL http://pkgs.fedoraproject.org/repo/pkgs/gtest/gtest-1.7.0.zip/2d6ec8ccdf5c46b05ba54a9fd1d130d7/gtest-1.7.0.zip)
endif ()
#You can specify the URL for google mock, so that it uses a computer location
if (NOT DEFINED GOOGLE_MOCK_URL)
    set(GOOGLE_MOCK_URL https://github.com/paulsapps/gmock-1.7.0/archive/master.zip)
endif ()
# Enable ExternalProject CMake modules
# We need thread support
find_package(Threads REQUIRED)

include(ExternalProject)
ExternalProject_Add(
        googletest
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
        GIT_REPOSITORY "https://github.com/google/googletest.git"
        GIT_TAG master
        INSTALL_COMMAND ""
        UPDATE_DISCONNECTED 1
)

ExternalProject_Get_Property(googletest source_dir binary_dir)

set_directory_properties(${binary_dir} CLEAN_NO_CUSTOM 1)

add_library(libgtest IMPORTED STATIC)
add_dependencies(libgtest googletest)

set_target_properties(libgtest PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest.a"
        )

include_directories(${source_dir}/googletest/include)


add_library(libgmock IMPORTED STATIC)

set_target_properties(libgmock PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/googlemock/libgmock.a"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}")

include_directories(.)
file(GLOB_RECURSE SRCS *UnitTest.cpp)

foreach(f ${SRCS})
    get_filename_component(f_we ${f} NAME_WE)
    get_filename_component(dir ${f} DIRECTORY)
    set(INPUT_NAME ${f_we}.txt)
    add_executable(${f_we} ${f} AllTests.cpp)
    add_test(NAME ${f_we} COMMAND ${f_we})
    target_link_libraries(${f_we} analisador_de_entropia_lib libgtest libgmock arithmetic_compressor_lib arithmetic_decompressor_lib)

    file(GLOB_RECURSE TXTS ${dir}/*.txt)
    foreach(TXT ${TXTS})
        get_filename_component(txt_name ${TXT} NAME)
        add_custom_command(
                TARGET ${f_we} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E create_symlink
                ${TXT}
                $<TARGET_FILE_DIR:${f_we}>/${txt_name}
        )

    endforeach()
endforeach()
