add_library(arithmetic_decompressor_lib ArithmeticDecoder.h ArithmeticDecoder.cpp)
add_executable(arithmetic_decompressor main.cpp)
target_link_libraries(arithmetic_decompressor_lib utils_lib analisador_de_entropia_lib)
target_link_libraries(arithmetic_decompressor arithmetic_decompressor_lib)

file(GLOB_RECURSE input_files *.dat)

foreach(input_file ${input_files})
    get_filename_component(filename ${input_file} NAME)
    add_custom_command(TARGET arithmetic_decompressor
            COMMAND ${CMAKE_COMMAND} -E create_symlink
            ${input_file} $<TARGET_FILE_DIR:arithmetic_decompressor>/${filename}
            COMMENT "Creating link from file ${input_file}")
endforeach()
