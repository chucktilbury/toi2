
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

target_compile_options(${PROJECT_NAME} PRIVATE "-Wall" "-Wextra" "-g" "-DTRACE")
