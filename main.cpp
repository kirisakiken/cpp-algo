#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <map>

#include "problems/leetcode.h"
#include "problems/leetcode75.h"
#include "data_structures/list_node.h"

template<typename T>
void printVector(const std::vector<T>& vec) {
  std::cout << "[ ";
  for (int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << ", ";
  }
  std::cout << "]" << std::endl;
}

template<typename T>
void printJaggedVector(const std::vector<std::vector<T>>& vec) {
  std::cout << "[ ";
  for (const auto& x : vec) {
    std::cout << "[ ";
    for (const auto& y : x) {
      std::cout << y << ", ";
    }
    std::cout << " ]";
  }
  std::cout << " ]" << std::endl;
}

void printTreeNodeVector(const std::vector<TreeNode*>& vec) {
  std::cout << "[ ";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << (*it)->val << ", ";
  }
  std::cout << "]" << std::endl;
}

void printLinkedList(leetcode::ListNode* head) {
  std::string res = "[";
  while (head != nullptr) {
    res += std::to_string(head->val);
    res += ",";
    head = head->next;
  }
  res += "]";
  std::cout << res << std::endl;
}

int main() {
  int res = lengthOfLastWord("a ");
  std::cout << res << std::endl;

  return 0;
}
