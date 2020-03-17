
project(toi)

add_executable(${PROJECT_NAME}
    main.c
)

target_link_libraries(${PROJECT_NAME}
    parser
    abstract
    parser_support
    expressions
    utils
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/../include
)

#set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/../bin")
target_compile_options(${PROJECT_NAME} PRIVATE "-Wall" "-Wextra" "-g" "-DTRACE")
