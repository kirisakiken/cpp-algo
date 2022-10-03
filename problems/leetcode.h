#pragma once

#include <string>
#include <vector>
#include "../data_structures/list_node.h"

namespace leetcode {
  /// LeetCode 13 - Roman to Integer
  /// https://leetcode.com/problems/roman-to-integer/
  int romanToInt(const std::string& s);

  /// LeetCode 14 - Longest Common Prefix
  /// https://leetcode.com/problems/longest-common-prefix/
  std::string longestCommonPrefix(const std::vector<std::string>& vec);

  /// LeetCode 20 - Valid Parentheses
  /// https://leetcode.com/problems/valid-parentheses/
  bool isValid(const std::string& str);

  /// LeetCode 21 - Merge Two Sorted Lists
  /// https://leetcode.com/problems/merge-two-sorted-lists/
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

  /// LeetCode 26 - Remove Duplicates from Sorted Array
  /// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
  int removeDuplicates(std::vector<int>& nums);

  /// LeetCode 66 - Plus One
  /// https://leetcode.com/problems/plus-one/
  std::vector<int> plusOne(std::vector<int>& vec);

  /// LeetCode70 - Climbing Stairs
  /// https://leetcode.com/problems/climbing-stairs/
  int climbStairs(int n);

  /// LeetCode 205 - Isomorphic Strings
  /// https://leetcode.com/problems/isomorphic-strings/
  bool isIsomorphic(std::string s, std::string t);

  /// LeetCode 242 - Valid Anagram
  /// https://leetcode.com/problems/valid-anagram/
  bool validAnagram(const std::string& a,const std::string& b);

  /// LeetCode 392 - Is Subsequence
  /// https://leetcode.com/problems/is-subsequence/
  bool isSubsequence(std::string s, std::string t);

  /// LeetCode 724 - Find Pivot Index
  /// https://leetcode.com/problems/find-pivot-index/
  int pivotIndex(std::vector<int>& nums);

  /// LeetCode 1480 - Running Sum of 1d Array
  /// https://leetcode.com/problems/running-sum-of-1d-array/
  std::vector<int> runningSum(std::vector<int>& nums);
}
