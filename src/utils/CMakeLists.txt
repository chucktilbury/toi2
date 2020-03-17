
project(utils)

add_library(utils STATIC
    errors.c
    fifo.c
    lifo.c
    linked_lists.c
    hash_table.c
    xxhash.c
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/../include
)

#set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/../lib")
target_compile_options(${PROJECT_NAME} PRIVATE "-Wall" "-g" "-DTRACE")
