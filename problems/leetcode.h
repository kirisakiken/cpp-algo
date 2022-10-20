#pragma once

#include <string>
#include <vector>
#include "../data_structures/list_node.h"
#include "../data_structures/tree_node.h"

namespace leetcode {
  /// LeetCode 2 - Add Two Numbers
  /// https://leetcode.com/problems/add-two-numbers/
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

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

  /// LeetCode 70 - Climbing Stairs
  /// https://leetcode.com/problems/climbing-stairs/
  int climbStairs(int n);

  /// LeetCode 88 - Merge Sorted Array
  /// https://leetcode.com/problems/merge-sorted-array/
  void merge(std::vector<int>& nums1, const int& m, const std::vector<int>& nums2, const int& n);

  /// LeetCode 94 - Binary Tree Inorder Traversal
  /// https://leetcode.com/problems/binary-tree-inorder-traversal/
  std::vector<int> inorderTraversal(TreeNode* root);

  /// LeetCode 108 - Convert Sorted Array to Binary Search Tree
  /// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
  TreeNode* sortedArrayToBST(const std::vector<int>& nums);

  /// LeetCode 118 - Pascal's Triangle
  /// https://leetcode.com/problems/pascals-triangle/
  std::vector<std::vector<int>> generate(const int& n);

  /// LeetCode 141 - Linked List Cycle
  /// https://leetcode.com/problems/linked-list-cycle/
  bool hasCycle(ListNode* head);

  /// LeetCode 205 - Isomorphic Strings
  /// https://leetcode.com/problems/isomorphic-strings/
  bool isIsomorphic(std::string s, std::string t);

  /// LeetCode 242 - Valid Anagram
  /// https://leetcode.com/problems/valid-anagram/
  bool validAnagram(const std::string& a,const std::string& b);

  /// LeetCode 392 - Is Subsequence
  /// https://leetcode.com/problems/is-subsequence/
  bool isSubsequence(std::string s, std::string t);

  /// LeetCode 482 - Licence Key Formatting
  /// https://leetcode.com/problems/license-key-formatting/
  std::string licenseKeyFormatting(std::string& s, int k);

  /// LeetCode 724 - Find Pivot Index
  /// https://leetcode.com/problems/find-pivot-index/
  int pivotIndex(std::vector<int>& nums);

  /// LeetCode 1480 - Running Sum of 1d Array
  /// https://leetcode.com/problems/running-sum-of-1d-array/
  std::vector<int> runningSum(std::vector<int>& nums);
}
