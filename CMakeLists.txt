cmake_minimum_required(VERSION 3.16)

project(tree-teamwork C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

enable_testing()

# Main
add_executable(main src/main.c src/BST/BST.h src/BST/BST.c)

# Tests
add_executable(bst_test tests/testBST.c src/BST/BST.h src/BST/BST.c)
add_test(NAME BstTest COMMAND bst_test)
