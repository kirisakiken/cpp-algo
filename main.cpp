#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <bitset>
#include <queue>
#include <stack>

#include "algo_tech/combination.h"
#include "algo_tech/permutation.h"
#include "templates/io_templates.h"
#include "problems/leetcode.h"
#include "templates/algo_templates.h"

using namespace leetcode;


int main() {
  std::vector<int> values = {1, 2, 3};
  auto res = get_permutations(values);
  printJaggedVector(res);

  return 0;
}
