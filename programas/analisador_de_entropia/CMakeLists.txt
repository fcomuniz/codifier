add_library(analisador_de_entropia_lib FirstOrderEntropyAnaliser.cpp FirstOrderEntropyAnaliser.h)
add_executable(analisador_de_entropia analisador_de_entropia.cpp)
target_link_libraries(analisador_de_entropia analisador_de_entropia_lib)

file(GLOB_RECURSE input_files *.txt)

foreach(input_file ${input_files})
    get_filename_component(filename ${input_file} NAME)
    add_custom_command(TARGET analisador_de_entropia
            COMMAND ${CMAKE_COMMAND} -E create_symlink
            ${input_file} $<TARGET_FILE_DIR:analisador_de_entropia>/${filename}
            COMMENT "Creating link from file ${input_file}")
endforeach()