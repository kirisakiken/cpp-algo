#pragma once

#include <string>
#include <vector>

namespace algo {
class leetcode {
  public:

  /// LeetCode 205 - Isomorphic Strings
  /// https://leetcode.com/problems/isomorphic-strings/
  bool isIsomorphic(std::string s, std::string t);

  /// LeetCode 242 - Valid Anagram
  /// https://leetcode.com/problems/valid-anagram/
  /// O(n) time, O(n) space
  bool validAnagram(const std::string& a,const std::string& b);

  /// LeetCode 392 - Is Subsequence
  /// https://leetcode.com/problems/is-subsequence/
  bool isSubsequence(std::string s, std::string t);

  /// LeetCode 724 - Find Pivot Index
  /// https://leetcode.com/problems/find-pivot-index/
  /// O(n) time, O(1) space
  int pivotIndex(std::vector<int>& nums);

  /// LeetCode 1480 - Running Sum of 1d Array
  /// https://leetcode.com/problems/running-sum-of-1d-array/
  std::vector<int> runningSum(std::vector<int>& nums);
};
}
