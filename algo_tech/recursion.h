#pragma once

#include "../data_structures/list_node.h"
#include "../data_structures/tree_node.h"
#include <string>

using namespace leetcode;

namespace algo_tech {
  std::string reverseString(std::string& str);
  bool isPalindrome(const std::string& str);
  std::string decimalToBinary(std::string& res, const int& num);
  int sumOfNatural(const int& n);
  ListNode* linkedListReversal(ListNode* head);
  ListNode* mergeSortedLinkedLists(ListNode* a, ListNode* b);
  TreeNode* bstInsert(TreeNode* root, int value);
  void printLeafNodes(TreeNode* root);
}
