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
    std::cout << " ]\n";
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

/// Slices a given vector using start/end indices and returns new vector
std::vector<int> vectorSlice(std::vector<int>& vec, const int& start, const int& end) {
  std::vector<int> res(end - start + 1);
  std::copy(vec.begin() + start, vec.begin() + end + 1, res.begin());
  return res;
}

/// Given vector, excludes the given index and returns new vector
std::vector<int> excludeIndex(const std::vector<int>& vec, const int& index) {
  std::vector<int> res(vec.size());
  std::copy(vec.begin(), vec.end(), res.begin());
  res.erase(res.begin() + index);
  return res;
}

int main() {
  std::vector<int> vec = {4, 2, 3, 0};
  std::cout << leetcode::missingNumber(vec);

  return 0;
}
