#include <iostream>

#include "problems/leetcode.h"

int main() {
  algo::leetcode leetcode;
  auto res = leetcode.isSubsequence("abc", "ahbgdc");
  std::cout << res << std::endl;
  return 0;
}
