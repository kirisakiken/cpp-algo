#pragma once

#include <string>
#include <vector>
#include "../data_structures/list_node.h"
#include "../data_structures/tree_node.h"

namespace leetcode {
  /// LeetCode 1 - Two Sum
  /// https://leetcode.com/problems/two-sum/description/
  std::vector<int> twoSum(const std::vector<int>& nums, int target);

  /// LeetCode 2 - Add Two Numbers
  /// https://leetcode.com/problems/add-two-numbers/
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

  /// LeetCode 3 - Longest Substring Without Repeating Characters
  /// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
  int lengthOfLongestSubstring(const std::string& s);

  /// LeetCode 9 - Palindrome Number
  /// https://leetcode.com/problems/palindrome-number/
  bool isPalindrome(const int& x);

  /// LeetCode 11 - Container With Most Water
  /// https://leetcode.com/problems/container-with-most-water/description/
  int maxArea(const std::vector<int>& height);

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

  /// LeetCode 36 - Valid Sudoku
  /// https://leetcode.com/problems/valid-sudoku/description/
  bool isValidSudoku(const std::vector<std::vector<char>>& board);

  /// LeetCode 46 - Permutations
  /// https://leetcode.com/problems/permutations/
  std::vector<std::vector<int>> permute(const std::vector<int>& nums);

  /// LeetCode 48 - Rotate Image
  /// https://leetcode.com/problems/rotate-image/description/
  void rotate(std::vector<std::vector<int>>& matrix);

  /// LeetCode 49 - Group Anagrams
  /// https://leetcode.com/problems/group-anagrams/
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);

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

  /// LeetCode 74 - Search a 2D Matrix
  /// https://leetcode.com/problems/search-a-2d-matrix/
  bool searchMatrix(const std::vector<std::vector<int>>& matrix, const int& target);

  /// LeetCode 75 - Sort Colors
  /// https://leetcode.com/problems/sort-colors/
  void sortColors(std::vector<int>& nums);

  /// LeetCode 77 - Combinations
  /// https://leetcode.com/problems/combinations/description/
  std::vector<std::vector<int>> combine(int n, int k);

  /// LeetCode 78 - Subsets
  /// https://leetcode.com/problems/subsets/
  std::vector<std::vector<int>> subsets(const std::vector<int>& nums);

  /// LeetCode 83 - Remove Duplicates from Sorted List
  /// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
  ListNode* deleteDuplicates(ListNode* head);

  /// LeetCode 88 - Merge Sorted Array
  /// https://leetcode.com/problems/merge-sorted-array/
  void merge(std::vector<int>& nums1, const int& m, const std::vector<int>& nums2, const int& n);

  /// LeetCode 94 - Binary Tree Inorder Traversal
  /// https://leetcode.com/problems/binary-tree-inorder-traversal/
  std::vector<int> inorderTraversal(TreeNode* root);

  /// LeetCode 100 - Same Tree
  /// https://leetcode.com/problems/same-tree/description/
  bool isSameTree(TreeNode* p, TreeNode* q);

  /// LeetCode 103 - Binary Tree Zigzag Level Order Traversal
  /// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root);

  /// LeetCode 104 - Maximum Depth of Binary Tree
  /// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
  int maxDepth(TreeNode* root);

  /// LeetCode 108 - Convert Sorted Array to Binary Search Tree
  /// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
  TreeNode* sortedArrayToBST(const std::vector<int>& nums);

  /// LeetCode 118 - Pascal's Triangle
  /// https://leetcode.com/problems/pascals-triangle/
  std::vector<std::vector<int>> generate(const int& n);

  /// LeetCode 121 - Best Time to Buy and Sell Stock
  /// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
  int maxProfit(const std::vector<int>& prices);

  /// LeetCode 125 - Valid Palindrome
  /// https://leetcode.com/problems/valid-palindrome/
  bool isPalindrome(std::string& s);

  /// LeetCode 136 - Single Number
  /// https://leetcode.com/problems/single-number/
  int singleNumber(std::vector<int>& nums);

  /// LeetCode 141 - Linked List Cycle
  /// https://leetcode.com/problems/linked-list-cycle/
  bool hasCycle(ListNode* head);

  /// LeetCode 148 - Sort List
  /// https://leetcode.com/problems/sort-list/
  ListNode* sortList(ListNode* head);

  /// LeetCode 150 - Evaluate Reverse Polish Notation
  /// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
  int evalRPN(const std::vector<std::string>& tokens);

  /// LeetCode 160 - Intersection of Two Linked Lists
  /// https://leetcode.com/problems/intersection-of-two-linked-lists/
  ListNode* getIntersectionNode(ListNode* a, ListNode* b);

  /// LeetCode 167 - Two Sum II - Input Array Is Sorted
  /// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
  std::vector<int> twoSum(const std::vector<int>& numbers, const int& target);

  /// LeetCode 169 - Majority Element
  /// https://leetcode.com/problems/majority-element/
  int majorityElement(std::vector<int>& nums);

  /// LeetCode 170 - Excel Sheet Column Number
  /// https://leetcode.com/problems/excel-sheet-column-number/
  int titleToNumber(const std::string& columnTitle);

  /// LeetCode 189 - Rotate Array
  /// https://leetcode.com/problems/rotate-array/description/
  void rotate(std::vector<int>& nums, int k);

  /// LeetCode 190 - Reverse Bits
  /// https://leetcode.com/problems/reverse-bits/
  uint32_t reverseBits(uint32_t n);

  /// LeetCode 191 - Number of 1 Bits
  /// https://leetcode.com/problems/number-of-1-bits/
  int hammingWeight(uint32_t n);

  /// LeetCode 202 - Happy Number
  /// https://leetcode.com/problems/happy-number/description/
  bool isHappy(int n);

  /// LeetCode 205 - Isomorphic Strings
  /// https://leetcode.com/problems/isomorphic-strings/
  bool isIsomorphic(std::string s, std::string t);

  /// LeetCode 217 - Contains Duplicate
  /// https://leetcode.com/problems/contains-duplicate/description/
  bool containsDuplicate(const std::vector<int>& nums);

  /// LeetCode 226 - Invert Binary Tree
  /// https://leetcode.com/problems/invert-binary-tree/description/
  TreeNode* invertTree(TreeNode* root);

  /// LeetCode 234 - Palindrome Linked List
  /// https://leetcode.com/problems/palindrome-linked-list/
  bool isPalindrome(ListNode* head);

  /// LeetCode 237 - Delete Node in a Linked List
  /// https://leetcode.com/problems/delete-node-in-a-linked-list/
  void deleteNode(ListNode* node);

  /// LeetCode 230 - Kth Smallest Element in BST
  /// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
  int kthSmallest(TreeNode* root, const int& k);

  /// LeetCode 238 - Product of Array Except Self
  /// https://leetcode.com/problems/product-of-array-except-self/description/
  std::vector<int> productExceptSelf(const std::vector<int>& nums);

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

  /// LeetCode 328 - Odd Even Linked List (reverse zipper)
  /// https://leetcode.com/problems/odd-even-linked-list/
  ListNode* oddEvenList(ListNode* head);

  /// LeetCode 344 - Reverse String
  /// https://leetcode.com/problems/reverse-string/
  void reverseString(std::vector<char>& s);

  /// LeetCode 347 - Top K Frequent Elements
  /// https://leetcode.com/problems/top-k-frequent-elements/
  std::vector<int> topKFrequent(const std::vector<int>& nums, const int& k);

  /// LeetCode 350 - Intersection of Two Arrays II
  /// https://leetcode.com/problems/intersection-of-two-arrays-ii/
  std::vector<int> intersect(const std::vector<int>& nums1, const std::vector<int>& nums2);

  /// LeetCode 383 - Ransom Note
  /// https://leetcode.com/problems/ransom-note/description/
  bool canConstruct(const std::string& ransomNote, const std::string& magazine);

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

  /// LeetCode 804 - Unique Morse Code Words
  /// https://leetcode.com/problems/unique-morse-code-words/description/
  int uniqueMorseRepresentations(const std::vector<std::string>& words);

  /// LeetCode 1313 - Decompress Run-Length Encoded List
  /// https://leetcode.com/problems/decompress-run-length-encoded-list/
  std::vector<int> decompressRLElist(const std::vector<int>& nums);

  /// LeetCode 1365 - How Many Numbers Are Smaller Than the Current Number
  /// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
  std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums);

  /// LeetCode 1389 - Create Target Array in the Given Order
  /// https://leetcode.com/problems/create-target-array-in-the-given-order/
  std::vector<int> createTargetArray(std::vector<int>& nums, std::vector<int>& index);

  /// LeetCode 1431 - Kids With the Greatest Number of Candies
  /// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/
  std::vector<bool> kidsWithCandies(const std::vector<int>& candies, int extraCandies);

  /// LeetCode 1480 - Running Sum of 1d Array
  /// https://leetcode.com/problems/running-sum-of-1d-array/
  std::vector<int> runningSum(std::vector<int>& nums);

  /// LeetCode 1470 - Shuffle the Array
  /// https://leetcode.com/problems/shuffle-the-array/description/
  std::vector<int> shuffle(std::vector<int>& nums, int n);

  /// LeetCode 1512 - Number of Good Pairs
  /// https://leetcode.com/problems/number-of-good-pairs/description/
  int numIdenticalPairs(const std::vector<int>& nums);

  /// LeetCode 1528 - Shuffle String
  /// https://leetcode.com/problems/shuffle-string/
  std::string restoreString(const std::string& s, const std::vector<int>& indices);

  /// LeetCode 1572 - Matrix Diagonal Sum
  /// https://leetcode.com/problems/matrix-diagonal-sum/description/
  int diagonalSum(const std::vector<std::vector<int>>& mat);

  /// LeetCode 1662 - Check If Two String Arrays are Equivalent
  /// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/
  bool arrayStringsAreEqual(const std::vector<std::string>& word1, const std::vector<std::string>& word2);

  /// LeetCode 1672 - Richest Customer Wealth
  /// https://leetcode.com/problems/richest-customer-wealth/description/
  int maximumWealth(const std::vector<std::vector<int>>& accounts);

  /// LeetCode 1684 - Count the Number of Consistent Strings
  /// https://leetcode.com/problems/count-the-number-of-consistent-strings/description/
  int countConsistentStrings(const std::string& allowed, const std::vector<std::string>& words);

  /// LeetCode 1816 - Truncate Sentence
  /// https://leetcode.com/problems/truncate-sentence/description/
  std::string truncateSentence(const std::string& s, int k);

  /// LeetCode 1920 - Build Array from Permutation
  /// https://leetcode.com/problems/build-array-from-permutation/description/
  std::vector<int> buildArray(const std::vector<int>& nums);

  /// LeetCode 1773 - Count Items Matching a Rule
  /// https://leetcode.com/problems/count-items-matching-a-rule/description/
  int countMatches(const std::vector<std::vector<std::string>>& items, const std::string& ruleKey, const std::string& ruleValue);

  /// LeetCode 1929 - Concatenation of Array
  /// https://leetcode.com/problems/concatenation-of-array/description/
  std::vector<int> getConcatenation(std::vector<int>& nums);

  /// LeetCode 2006 - Count Number of Pairs With Absolute Difference K
  /// https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/description/
  int countKDifference(const std::vector<int>& nums, int k);

  /// LeetCode 2011 - Final Value of Variable After Performing Operations
  /// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/
  int finalValueAfterOperations(const std::vector<std::string>& operations);

  /// LeetCode 2114 - Maximum Number of Words Found in Sentences
  /// https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/description/
  int mostWordsFound(const std::vector<std::string>& sentences);

  /// LeetCode 2535 - Difference Between Element Sum and Digit Sum of an Array
  /// https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/description/
  int differenceOfSum(const std::vector<int>& nums);

  /// LeetCode 2574 - Left and Right Sum Differences
  /// https://leetcode.com/problems/left-and-right-sum-differences/description/
  std::vector<int> leftRigthDifference(const std::vector<int>& nums);

  /// LeetCode 2652 - Sum Multiples
  /// https://leetcode.com/problems/sum-multiples/description/
  int sumOfMultiples(int n);
}
