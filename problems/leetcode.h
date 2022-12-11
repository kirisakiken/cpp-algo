#pragma once

#include <string>
#include <vector>
#include "../data_structures/list_node.h"
#include "../data_structures/tree_node.h"

namespace leetcode {
  /// LeetCode 2 - Add Two Numbers
  /// https://leetcode.com/problems/add-two-numbers/
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

  /// LeetCode 9 - Palindrome Number
  /// https://leetcode.com/problems/palindrome-number/
  bool isPalindrome(const int& x);

  /// LeetCode 13 - Roman to Integer
  /// https://leetcode.com/problems/roman-to-integer/
  int romanToInt(const std::string& s);

  /// LeetCode 14 - Longest Common Prefix
  /// https://leetcode.com/problems/longest-common-prefix/
  std::string longestCommonPrefix(const std::vector<std::string>& vec);

  /// LeetCode 19 - Remove Nth Node From End of List
  /// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
  ListNode* removeNthFromEnd(ListNode* head, const int& n);

  /// LeetCode 20 - Valid Parentheses
  /// https://leetcode.com/problems/valid-parentheses/
  bool isValid(const std::string& str);

  /// LeetCode 21 - Merge Two Sorted Lists
  /// https://leetcode.com/problems/merge-two-sorted-lists/
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

  /// LeetCode 26 - Remove Duplicates from Sorted Array
  /// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
  int removeDuplicates(std::vector<int>& nums);

  /// LeetCode 27 - Remove Element
  /// https://leetcode.com/problems/remove-element/
  int removeElement(std::vector<int>& nums, const int& val);

  /// LeetCode 58 - Length of Last Word
  /// https://leetcode.com/problems/length-of-last-word/
  int lengthOfLastWord(const std::string& s);

  /// LeetCode 66 - Plus One
  /// https://leetcode.com/problems/plus-one/
  std::vector<int> plusOne(std::vector<int>& vec);

  /// LeetCode 70 - Climbing Stairs
  /// https://leetcode.com/problems/climbing-stairs/
  int climbStairs(int n);

  /// LeetCode 73 - Set Matrix Zeros
  /// https://leetcode.com/problems/set-matrix-zeroes/
  void setZeroes(std::vector<std::vector<int>>& matrix);

  /// LeetCode 75 - Sort Colors
  /// https://leetcode.com/problems/sort-colors/
  void sortColors(std::vector<int>& nums);

  /// LeetCode 77 - Combinations
  /// https://leetcode.com/problems/combinations/description/
  std::vector<std::vector<int>> combine(int n, int k);

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

  /// LeetCode 125 - Valid Palindrome
  /// https://leetcode.com/problems/valid-palindrome/
  bool isPalindrome(std::string& s);

  /// LeetCode 136 - Single Number
  /// https://leetcode.com/problems/single-number/
  int singleNumber(std::vector<int>& nums);

  /// LeetCode 141 - Linked List Cycle
  /// https://leetcode.com/problems/linked-list-cycle/
  bool hasCycle(ListNode* head);

  /// LeetCode 160 - Intersection of Two Linked Lists
  /// https://leetcode.com/problems/intersection-of-two-linked-lists/
  ListNode* getIntersectionNode(ListNode* a, ListNode* b);

  /// LeetCode 169 - Majority Element
  /// https://leetcode.com/problems/majority-element/
  int majorityElement(std::vector<int>& nums);

  /// LeetCode 170 - Excel Sheet Column Number
  /// https://leetcode.com/problems/excel-sheet-column-number/
  int titleToNumber(const std::string& columnTitle);

  /// LeetCode 190 - Reverse Bits
  /// https://leetcode.com/problems/reverse-bits/
  uint32_t reverseBits(uint32_t n);

  /// LeetCode 191 - Number of 1 Bits
  /// https://leetcode.com/problems/number-of-1-bits/
  int hammingWeight(uint32_t n);

  /// LeetCode 205 - Isomorphic Strings
  /// https://leetcode.com/problems/isomorphic-strings/
  bool isIsomorphic(std::string s, std::string t);

  /// LeetCode 234 - Palindrome Linked List
  /// https://leetcode.com/problems/palindrome-linked-list/
  bool isPalindrome(ListNode* head);

  /// LeetCode 237 - Delete Node in a Linked List
  /// https://leetcode.com/problems/delete-node-in-a-linked-list/
  void deleteNode(ListNode* node);

  /// LeetCode 230 - Kth Smallest Element in BST
  /// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
  int kthSmallest(TreeNode* root, const int& k);

  /// LeetCode 242 - Valid Anagram
  /// https://leetcode.com/problems/valid-anagram/
  bool validAnagram(const std::string& a,const std::string& b);

  /// LeetCode 268 - Missing number
  /// https://leetcode.com/problems/missing-number/
  int missingNumber(std::vector<int>& nums);

  /// LeetCode 283 - Move Zeros
  /// https://leetcode.com/problems/move-zeroes/
  void moveZeroes(std::vector<int>& nums);

  /// LeetCode 326 - Power of Three
  /// https://leetcode.com/problems/power-of-three/
  bool isPowerOfThree(int& n);

  /// LeetCode 344 - Reverse String
  /// https://leetcode.com/problems/reverse-string/
  void reverseString(std::vector<char>& s);

  /// LeetCode 347 - Top K Frequent Elements
  /// https://leetcode.com/problems/top-k-frequent-elements/
  std::vector<int> topKFrequent(const std::vector<int>& nums, const int& k);

  /// LeetCode 350 - Intersection of Two Arrays II
  /// https://leetcode.com/problems/intersection-of-two-arrays-ii/
  std::vector<int> intersect(const std::vector<int>& nums1, const std::vector<int>& nums2);

  /// LeetCode 387 - First Unique Character in a String
  /// https://leetcode.com/problems/first-unique-character-in-a-string/
  int firstUniqChar(const std::string& s);

  /// LeetCode 392 - Is Subsequence
  /// https://leetcode.com/problems/is-subsequence/
  bool isSubsequence(std::string s, std::string t);

  /// LeetCode 412 - Fizz Buzz
  /// https://leetcode.com/problems/fizz-buzz/
  std::vector<std::string> fizzBuzz(const int& n);

  /// LeetCode 482 - Licence Key Formatting
  /// https://leetcode.com/problems/license-key-formatting/
  std::string licenseKeyFormatting(std::string& s, int k);

  /// LeetCode 695 - Max Area of Island
  /// https://leetcode.com/problems/max-area-of-island/
  int maxAreaOfIsland(std::vector<std::vector<int>>& grid);

  /// LeetCode 724 - Find Pivot Index
  /// https://leetcode.com/problems/find-pivot-index/
  int pivotIndex(std::vector<int>& nums);

  /// LeetCode 1480 - Running Sum of 1d Array
  /// https://leetcode.com/problems/running-sum-of-1d-array/
  std::vector<int> runningSum(std::vector<int>& nums);
}
