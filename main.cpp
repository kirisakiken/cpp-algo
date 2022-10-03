#include <iostream>

#include "problems/leetcode.h"
#include "problems/leetcode75.h"
#include "data_structures/list_node.h"
#include "problems/tester.cpp"

template<typename T>
void printVector(const std::vector<T>& vec) {
  std::cout << "[ ";
  for (int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << ", ";
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
  std::vector<int> vec{1, 2, 3};
//  auto res = leetcode::plusOne(vec);
//  printVector(res);
  std::cout << *(vec.end() - 1);
  return 0;
}
