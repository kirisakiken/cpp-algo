#include <iostream>
#include <vector>
#include <string>

#include "io_templates.h"

void printTreeNodeVector(const std::vector<leetcode::TreeNode*>& vec) {
  std::cout << "[ ";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << (*it)->val << ", ";
  }
  std::cout << "]" << std::endl;
}

void printLinkedListVector(const std::vector<leetcode::ListNode*>& vec) {
  std::cout << "[ ";
  for (const auto& e : vec) {
    std::cout << e->val << ", ";
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

std::vector<int> vectorSlice(std::vector<int>& vec, const int& start, const int& end) {
  std::vector<int> res(end - start + 1);
  std::copy(vec.begin() + start, vec.begin() + end + 1, res.begin());
  return res;
}

std::vector<int> excludeIndex(const std::vector<int>& vec, const int& index) {
  std::vector<int> res(vec.size() - 1);
  std::copy(vec.begin(), vec.begin() + index, res.begin());
  std::copy(vec.begin() + index + 1, vec.end(), res.begin() + index);

  return res;
}
