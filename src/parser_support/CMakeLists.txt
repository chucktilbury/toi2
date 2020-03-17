
project(parser_support)

add_library(${PROJECT_NAME}
    STATIC
        assignment_rules.c
        common_branch_rules.c
        function_call_rules.c
        literal_value_rules.c
        expression_def_rules.c
        if_else_rules.c
        switch_case_rules.c
        class_def_rules.c
        data_def_rules.c
        function_def_rules.c
        module_rules.c
        for_loop_rules.c
        import_rules.c
        while_rules.c
        except_rules.c
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/../include
        ${PROJECT_SOURCE_DIR}/../parser
)

#set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/../lib")
target_compile_options(${PROJECT_NAME} PRIVATE "-Wall" "-Wextra" "-g" "-DTRACE")
