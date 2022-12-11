#pragma once

#include "../data_structures/tree_node.h"
#include "../data_structures/list_node.h"

/// Prints given vector
template<typename T>
void printVector(const std::vector<T>& vec) {
  std::cout << "[ ";
  for (int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << ", ";
  }
  std::cout << "]" << std::endl;
}

/// Prints elements of jagged vector. aka matrix
template<typename T>
void printJaggedVector(const std::vector<std::vector<T>>& vec) {
  std::cout << "[ ";
  for (const auto& x : vec) {
    std::cout << "[ ";
    for (const auto& y : x) {
      std::cout << y << ", ";
    }
    std::cout << " ]\n";
  }
  std::cout << " ]" << std::endl;
}

/// Prints given vector of tree nodes
void printTreeNodeVector(const std::vector<leetcode::TreeNode*>& vec);

/// Prints given vector of linked list
void printLinkedListVector(const std::vector<leetcode::ListNode*>& vec);

/// Prints given linked list
void printLinkedList(leetcode::ListNode* head);

/// Slices a given vector using start/end indices and returns new vector
std::vector<int> vectorSlice(std::vector<int>& vec, const int& start, const int& end);

/// Given vector, excludes the given index and returns new vector
std::vector<int> excludeIndex(const std::vector<int>& vec, const int& index);
