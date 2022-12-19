#pragma once

#include <vector>

template<typename T>
std::vector<std::vector<T>> get_permutations(const std::vector<T>& vec) {
  if (vec.empty())
    return {{}};

  T first = vec[0];
  std::vector<T> rest(vec.begin() + 1, vec.end());

  std::vector<std::vector<T>> permsWithoutFirst = get_permutations(rest);
  std::vector<std::vector<T>> allPermutations = {};

  for (std::vector<T>& perm : permsWithoutFirst) {
    for (int i = 0; i <= perm.size(); ++i) {
      std::vector<int> permutationWithFirst(perm.begin(), perm.end());
      permutationWithFirst.insert(permutationWithFirst.begin() + i, first);

      allPermutations.push_back(permutationWithFirst);
    }
  }

  return allPermutations;
}

template<typename T>
std::vector<std::vector<T>> get_combinations(const std::vector<T>& vec) {
  if (vec.empty())
    return {{}};

  T first = vec[0];
  std::vector<T> rest(vec.begin() + 1, vec.end());

  std::vector<std::vector<T>> combinationsWithoutFirst = get_combinations(rest);
  std::vector<std::vector<T>> combinationsWithFirst = {};

  for (const std::vector<T>& comb : combinationsWithoutFirst) {
    std::vector<T> combinationWithFirst(comb.begin(), comb.end());
    combinationWithFirst.push_back(first);

    combinationsWithFirst.push_back(combinationWithFirst);
  }

  std::vector<std::vector<T>> result(combinationsWithoutFirst.begin(), combinationsWithoutFirst.end());
  result.insert(result.end(), combinationsWithFirst.begin(), combinationsWithFirst.end());

  return result;
}



















