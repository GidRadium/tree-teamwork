cmake_minimum_required(VERSION 3.16)

project(tree-teamwork C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# BST library
add_library(bst STATIC src/BST/BST.c src/BST/BST.h)
target_include_directories(bst PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/BST)

# Main
add_executable(main src/main.c)
target_link_libraries(main PRIVATE bst)

# Tests
enable_testing()
add_executable(bst_test tests/testBST.c)
target_link_libraries(bst_test PRIVATE bst)
add_test(NAME BstTest COMMAND bst_test)
