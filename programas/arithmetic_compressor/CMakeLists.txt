add_library(arithmetic_compressor_lib ArithmeticEncoder.h ArithmeticEncoder.cpp)
add_executable(arithmetic_compressor main.cpp)
target_link_libraries(arithmetic_compressor_lib utils_lib analisador_de_entropia_lib)
target_link_libraries(arithmetic_compressor arithmetic_compressor_lib)

file(GLOB_RECURSE input_files *.txt)

foreach(input_file ${input_files})
    get_filename_component(filename ${input_file} NAME)
    add_custom_command(TARGET arithmetic_compressor
            COMMAND ${CMAKE_COMMAND} -E create_symlink
            ${input_file} $<TARGET_FILE_DIR:arithmetic_compressor>/${filename}
            COMMENT "Creating link from file ${input_file}")
endforeach()
