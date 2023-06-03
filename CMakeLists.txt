cmake_minimum_required(VERSION 3.15)
project(password-checker VERSION 0.0.1 DESCRIPTION "password checker that uses a trie bst")

add_executable(${PROJECT_NAME}
    trie.c
    main.c
)

target_include_directories(${PROJECT_NAME} PRIVATE
    headers
)

set(CMAKE_C_COMPILER "gcc-6.3")

set_target_properties(${PROJECT_NAME} PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED ON
)



