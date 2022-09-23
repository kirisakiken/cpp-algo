#include <iostream>

#include "problems/leetcode.h"

int main() {
  algo::leetcode leetcode;
  std::vector<int> vec = {1, 7, 3, 6, 5, 6};
  auto res = leetcode.pivotIndex(vec);
  std::cout << res << std::endl;
  return 0;
}
