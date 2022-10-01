#include <iostream>

#include "problems/leetcode.h"
#include "problems/leetcode75.h"

void printVector(const std::vector<int>& vec) {
  std::cout << "[ ";
  for (int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << ", ";
  }
  std::cout << "]" << std::endl;
}

int main() {
  return 0;
}
