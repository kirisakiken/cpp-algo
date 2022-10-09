#include "leetcode75.h"
#include <map>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

namespace leetcode75 {
  std::vector<int> runningSum(const std::vector<int>& nums) {
    std::vector<int> result;

    result.push_back(nums[0]);
    for (int i = 1; i < nums.size(); ++i) {
      result.push_back(nums[i] + result[i - 1]);
    }

    return result;
  }

  int pivotIndex(const std::vector<int>& nums) {
    int leftSum = 0;
    int sum = 0;
    for (int value : nums)
      sum += value;

    for (int i = 0; i < nums.size(); ++i) {
      if (leftSum == (sum - leftSum - nums[i]))
        return i;

      leftSum += nums[i];
    }

    return -1;
  }

  bool isIsomorphic(const std::string& s, const std::string& t) {
    if (s.length() != t.length())
      return false;

    std::map<char, char> map;
    for (int i = 0; i < s.length(); ++i) {
      if (map.find(s[i]) == map.end()) {
        // traverse map to see if value already exists
        for (const auto& v : map) {
          if (v.second == t[i])
            return false;
        }

        map[s[i]] = t[i];
      }

      if (map[s[i]] != t[i])
        return false;
    }

    return true;
  }

  bool isSubsequence(const std::string& s, std::string t) {
    if (s.length() > t.length())
      return false;

    auto index = s.begin();
    auto it = t.begin();

    while (it != t.end()) {
      if (*it != *index) {
        it = t.erase(it);
      } else {
        ++it;

        if (index == s.end())
          break;

        ++index;
      }
    }

    return s == t;
  }

  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr && list2 == nullptr)
      return nullptr;
    if (list1 == nullptr)
      return list2;
    if (list2 == nullptr)
      return list1;

    ListNode* head = list1->val < list2->val
        ? list1
        : list2;

    ListNode* nextA;
    ListNode* nextB;
    if (head == list1) {
      nextA = head->next;
      nextB = list2;
    } else {
      nextA = list1;
      nextB = head->next;
    }

    ListNode* current = head;
    while (nextA != nullptr && nextB != nullptr) {
      if (nextA->val < nextB->val) {
        current->next = nextA;
        current = current->next;
        nextA = current->next;
      } else {
        current->next = nextB;
        current = current->next;
        nextB = current->next;
      }
    }

    if (nextA != nullptr)
      current->next = nextA;

    if (nextB != nullptr)
      current->next = nextB;

    return head;
  }

  ListNode* reverseList(ListNode* head) {
    ListNode* previous = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current != nullptr) {
      next = current->next;
      current->next = previous;
      previous = current;
      current = next;
    }

    return previous;
  }

  ListNode* middleNode(ListNode* head) {
    int count = 1;

    ListNode* current = head;
    while (current != nullptr) {
      count++;
      current = current->next;
    }

    int mid = count % 2 == 0
        ? count / 2
        : (count / 2) + 1;
    current = head;
    for (int i = 0; i < mid; ++i) {
      current = current->next;
    }

    return current;
  }

  ListNode* detectCycle(ListNode* head) {
    if (head == nullptr)
      return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && slow->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;

      if (fast == slow)
        break;
    }

    if (fast->next == nullptr || fast->next->next == nullptr)
      return nullptr;

    fast = head;
    while (true) {
      if (slow == fast)
        return slow;

      slow = slow->next;
      fast = fast->next;
    }

    return nullptr;
  }

  int maxProfit(const std::vector<int>& prices) {
    int left = 0;
    int right = 1;
    int max = 0;

    while (right < prices.size()) {
      if (prices[right] > prices[left])
        max = std::max(prices[right] - prices[left], max);
      else
        left = right;

      ++right;
    }

    return max;
  }

  int longestPalindrome(const std::string& s) {
    std::unordered_map<char, int> map;
    for (const char& c : s) {
      ++map[c];
    }

    int pairCount = 0;
    int odd = 0;
    for (const auto& kvp : map) {
      pairCount += kvp.second / 2;
      odd += kvp.second % 2 != 0;
    }

    return (pairCount * 2) + (odd != 0);
  }

  void recTreeValuesDfs(std::vector<int>& values, std::stack<Node*>& stack) {
    if (stack.empty())
      return;

    auto* current = stack.top();
    stack.pop();
    if (current == nullptr)
      recTreeValuesDfs(values, stack);
    else {
      values.push_back(current->val);

      for (int i = current->children.size() - 1; i >= 0; --i) {
        stack.push(current->children[i]);
      }

      recTreeValuesDfs(values, stack);
    }
  }

  std::vector<int> preorder(Node* root) {
    std::vector<int> res;
    std::stack<Node*> stack;

    stack.push(root);
    recTreeValuesDfs(res, stack);

    return res;
  }

  std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr)
      return {};

    std::vector<std::vector<int>> res;
    std::queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
      std::vector<int> sub;
      int len = queue.size();

      for (int i = 0; i < len; ++i) {
        auto* current = queue.front();
        queue.pop();

        if (current->left != nullptr)
          queue.push(current->left);
        if (current->right != nullptr)
          queue.push(current->right);

        sub.push_back(current->val);
      }

      res.push_back(sub);
    }

    return res;
  }

  int search(const std::vector<int>& nums, const int& target) {
    int left = 0;
    int right = nums.size() - 1;
    int pivot;

    while (right >= left) {
      pivot = (left + right) / 2;

      if (nums[pivot] == target)
        return pivot;

      if (nums[pivot] > target)
        right = pivot - 1;

      if (nums[pivot] < target)
        left = pivot + 1;
    }

    return -1;
  }

  int firstBadVersion(int n) {
    int left = 0;
    int right = n;
    int pivot;

    while (right >= left) {
      pivot = left + (right - left) / 2;
      if (isBadVersion(pivot)) {
        if (!isBadVersion(pivot - 1))
          return pivot - 1;

        right = pivot;
        continue;
      }
      else {
        left = pivot;
        continue;
      }
    }

    return -1;
  }
}
























