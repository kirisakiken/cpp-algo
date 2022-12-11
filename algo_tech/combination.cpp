#include "combination.h"

std::vector<int> v_slice_copy(std::vector<int>& vec, int start, int end) {
  std::vector<int> res(end - start + 1);
  std::copy(vec.begin() + start, vec.begin() + end + 1, res.begin());
  return res;
}

std::vector<std::vector<int>> combinations(std::vector<int>& values) {
  if (values.empty())
    return {{}};

  int first = values[0];
  std::vector<int> rest = v_slice_copy(values, 1, values.size() - 1);

  std::vector<std::vector<int>> combinationsWithoutFirst = combinations(rest);
  std::vector<std::vector<int>> combinationsWithFirst = {};

  for (const std::vector<int>& comb : combinationsWithoutFirst) {
    std::vector<int> combinationWithFirst{};
    combinationWithFirst.insert(combinationWithFirst.end(), comb.begin(), comb.end());
    combinationWithFirst.push_back(first);

    combinationsWithFirst.push_back(combinationWithFirst);
  }

  std::vector<std::vector<int>> result{};
  result.insert(result.end(), combinationsWithoutFirst.begin(), combinationsWithoutFirst.end());
  result.insert(result.end(), combinationsWithFirst.begin(), combinationsWithFirst.end());
  return result;
}
