#pragma once

#include <vector>
#include <string>
#include "../data_structures/list_node.h"
#include "../data_structures/node.h"
#include "../data_structures/tree_node.h"

using namespace leetcode;

namespace leetcode75 {
  /// Level1 - Day1

  /// LeetCode 1480 - Running Sum of 1d Array
  /// https://leetcode.com/problems/running-sum-of-1d-array/
  std::vector<int> runningSum(const std::vector<int>& nums);

  /// LeetCode 724 - Find Pivot Index
  /// https://leetcode.com/problems/find-pivot-index/
  int pivotIndex(const std::vector<int>& nums);

  /// Level1 - Day2

  /// LeetCode 205 - Isomorphic Strings
  /// https://leetcode.com/problems/isomorphic-strings/
  bool isIsomorphic(const std::string& s, const std::string& t);

  /// LeetCode 392 - Is Subsequence
  /// https://leetcode.com/problems/is-subsequence/
  bool isSubsequence(const std::string& s, std::string t);

  /// Level1 - Day3

  /// LeetCode 21 - Merge Two Sorted Lists
  /// https://leetcode.com/problems/merge-two-sorted-lists/
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

  /// LeetCode 206 - Reverse Linked List
  /// https://leetcode.com/problems/reverse-linked-list/
  ListNode* reverseList(ListNode* head);

  /// Level1 - Day4

  /// LeetCode 876 - Middle of the Linked List
  /// https://leetcode.com/problems/middle-of-the-linked-list/
  ListNode* middleNode(ListNode* head);

  /// LeetCode 142 - Linked List Cycle II
  /// https://leetcode.com/problems/linked-list-cycle-ii/
  ListNode* detectCycle(ListNode* head);

  /// Level1 - Day5

  /// LeetCode 121 - Best Time to Buy and Sell Stock
  /// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
  int maxProfit(const std::vector<int>& prices);

  /// LeetCode 409 - Longest Palindrome
  /// https://leetcode.com/problems/longest-palindrome/
  int longestPalindrome(const std::string& s);

  /// Level1 - Day6

  /// LeetCode 589 - N-ary Tree Preorder Traversal
  /// https://leetcode.com/problems/n-ary-tree-preorder-traversal/
  std::vector<int> preorder(Node*);

  /// LeetCode 102 - Binary Tree Level Order Traversal
  /// https://leetcode.com/problems/binary-tree-level-order-traversal/
  std::vector<std::vector<int>> levelOrder(TreeNode* root);

  /// Level1 - Day7

  /// LeetCode 704 - Binary Search
  /// https://leetcode.com/problems/binary-search/
  int search(const std::vector<int>& nums, const int& target);

  /// LeetCode 278 - First Bad Version
  /// https://leetcode.com/problems/first-bad-version/
  bool isBadVersion(int version); // mock api call
  int firstBadVersion(int n);
}
