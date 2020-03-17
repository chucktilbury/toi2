
project(expressions)

add_library(${PROJECT_NAME} STATIC
    evaluate.c
    expressions.c
    arith.c
    bitwise.c
    boolean.c
    unary.c
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/../include
)

#set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/../lib")
#set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "${LIBRARY_OUTPUT_PATH}")
target_compile_options(${PROJECT_NAME} PRIVATE "-Wall" "-Wextra" "-g" "-DTRACE")
