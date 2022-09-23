#include <iostream>

#include "problems/leetcode.h"

int main() {
  algo::leetcode leetcode;
  auto res = leetcode.isIsomorphic("ali", "iaa");
  std::cout << res << std::endl;
  return 0;
}
