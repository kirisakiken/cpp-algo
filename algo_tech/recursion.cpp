#include "recursion.h"

#include <iostream>
#include <vector>

namespace algo_tech {
  std::string reverseString(std::string& str) {
    if (str.empty())
      return "";

    char first = str[0];
    std::string next = str.substr(1, str.size());
    return reverseString(next) + first;
  }

  bool isPalindrome(const std::string& str) {
    if (str.empty() || str.size() == 1) {
      return true;
    }

    if (*str.begin() == *(str.end() - 1)) {
      std::string sub = str.substr(1, str.size() - 2);
      return isPalindrome(sub);
    }

    return false;
  }

  std::string decimalToBinary(std::string& res, const int& num) {
    if (num == 0)
      return res;

    res = std::to_string(num % 2) + res;
    return decimalToBinary(res, num / 2);
  }

  int sumOfNatural(const int& n) {
    if (n == 0)
      return 0;

    return sumOfNatural(n - 1) + n;
  }

  ListNode* linkedListReversal(ListNode* head) {
    if (head->next == nullptr)
      return head;

    ListNode* prev = linkedListReversal(head->next);
    head->next->next = head;
    head->next = nullptr;
    return prev;
  }

  ListNode* mergeSortedLinkedLists(ListNode* a, ListNode* b) {
    if (a == nullptr)
      return b;
    if (b == nullptr)
      return a;

    if (a->val < b->val) {
      a->next = mergeSortedLinkedLists(a->next, b);
      return a;
    }
    else {
      b->next = mergeSortedLinkedLists(a, b->next);
      return b;
    }
  }

  TreeNode* bstInsert(TreeNode* root, int value) {
    if (root == nullptr) {
      root = new TreeNode(value);
      return root;
    }

    if (root->val < value)
      root->right = bstInsert(root->right, value);
    else
      root->left = bstInsert(root->left, value);

    return root;
  }

  void printLeafNodes(TreeNode* root) {
    if (root == nullptr)
      return;

    if (root->left == nullptr && root->right == nullptr) {
      std::cout << root->val << std::endl;
      return;
    }

    if (root->left != nullptr)
      printLeafNodes(root->left);
    if (root->right != nullptr)
      printLeafNodes(root->right);
  }
}