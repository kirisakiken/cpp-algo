#include "permutation.h"

std::vector<std::vector<int>> permutations(const std::vector<int>& elements) {
  if (elements.empty())
    return {{}};

  int first = elements[0];
  std::vector<int> rest(elements.size() - 1);
  std::copy(elements.begin() + 1, elements.end(), rest.begin());

  std::vector<std::vector<int>> permsWithoutFirst = permutations(rest);
  std::vector<std::vector<int>> allPermutations = {};

  for (const std::vector<int>& perm : permsWithoutFirst) {
    for (int i = 0; i <= perm.size(); ++i) {
      std::vector<int> permutationWithFirst(perm.size());
      std::copy(perm.begin(), perm.end(), permutationWithFirst.begin());
      permutationWithFirst.insert(permutationWithFirst.begin() + i, first);

      allPermutations.push_back(permutationWithFirst);
    }
  }

  return allPermutations;
}
