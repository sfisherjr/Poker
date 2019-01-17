file(GLOB files "*.png")
foreach(file ${files})
    configure_file(${file} ${CMAKE_BINARY_DIR}/media/Cards COPYONLY)
endforeach()