
project(abstract)

add_library(${PROJECT_NAME} STATIC
    ast_attributes.c
    ast_tree.c
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/../include
)

target_compile_options(${PROJECT_NAME} PRIVATE "-Wall" "-Wextra" "-g" "-DTRACE")
