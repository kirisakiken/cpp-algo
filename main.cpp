#include <iostream>

#include "problems/leetcode.h"

int main() {
  algo::leetcode leetcode;
  std::vector<int> vec = {1, 7, 3, 6, 5, 6};
  auto res = leetcode.runningSum(vec);
  for (int val : res) {
    std::cout << val << " ";
  }
  std::cout << "\n";
  return 0;
}
