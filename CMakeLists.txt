cmake_minimum_required(VERSION 3.20)
project(cpp_algo)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        cpp_algo main.cpp
        templates/io_templates.cpp
        templates/algo_templates.cpp
        problems/leetcode.cpp
        problems/leetcode75.cpp
        data_structures/list_node.cpp
        data_structures/node.cpp
        data_structures/tree_node.cpp
        algo_tech/recursion.cpp
        algo_tech/combination.cpp
        algo_tech/permutation.cpp
)
