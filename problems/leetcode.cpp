#include "leetcode.h"

#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <algorithm>

namespace leetcode {
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto* prev = new ListNode();
    ListNode* current = prev;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
      int v1 = l1 != nullptr ? l1->val : 0;
      int v2 = l2 != nullptr ? l2->val : 0;

      int val = v1 + v2 + carry;
      carry = val / 10;
      val = val % 10;
      current->next = new ListNode(val);

      current = current->next;
      l1 = l1 != nullptr ? l1->next : nullptr;
      l2 = l2 != nullptr ? l2->next : nullptr;
    }

    return prev->next;
  }

  int romanToInt(const std::string& s) {
    int sum = 0;
    char previous = 0;

    for (char c : s) {
      switch (c) {
        default:
          break;

        case 'I': {
          sum += 1;
          break;
        }
        case 'V': {
          sum += 5;
          if (previous == 'I')
            sum -= 2;

          break;
        }
        case 'X': {
          sum += 10;
          if (previous == 'I')
            sum -= 2;

          break;
        }
        case 'L': {
          sum += 50;
          if (previous == 'X')
            sum -= 20;

          break;
        }
        case 'C': {
          sum += 100;
          if (previous == 'X')
            sum -= 20;

          break;
        }
        case 'D': {
          sum += 500;
          if (previous == 'C')
            sum -= 200;

          break;
        }
        case 'M': {
          sum += 1000;
          if (previous == 'C')
            sum -= 200;

          break;
        }
      }

      previous = c;
    }

    return sum;
  }

  std::string longestCommonPrefix(const std::vector<std::string>& vec) {
    std::string result{};
    std::vector<char> chars;
    int limit = INT_MAX;
    int clock = 0;

    for (const auto& str : vec) {
      if (str.length() >= limit)
        continue;

      limit = str.length();
    }

    while (clock < limit) {
      for (const std::string& str : vec)
        chars.push_back(str[clock]);

      char first = chars[0];
      for (int i = 1; i < chars.size(); ++i) {
        if (chars[i] != first)
          return result;
      }

      result.push_back(first);
      ++clock;
      chars.clear();
    }

    return result;
  }

  bool isValid(const std::string& str) {
    if (str.length() % 2 != 0)
      return false;

    std::map<char, char> map {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
    };
    std::map<char, bool> types {
        {'(', true},
        {')', false},
        {'[', true},
        {']', false},
        {'{', true},
        {'}', false},
    };

    std::stack<char> stack;

    for (const char& c : str) {
      if (types[c]) {
        stack.push(map[c]);
        continue;
      }

      if (stack.empty())
        return false;

      char top = stack.top();
      stack.pop();

      if (top != c)
        return false;
    }

    return stack.empty();
  }

  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr && list2 == nullptr)
      return nullptr;
    if (list1 != nullptr && list2 == nullptr)
      return list1;
    if (list1 == nullptr && list2 != nullptr)
      return list2;

    ListNode* head;

    ListNode* nextA;
    ListNode* nextB;
    ListNode* current;

    // get head
    if (list1->val < list2->val) {
      head = list1;
      nextA = head->next;
      nextB = list2;
    }
    else {
      head = list2;
      nextA = list1;
      nextB = head->next;
    }

    current = head;
    while (nextB != nullptr && nextA != nullptr) {
      if (nextB->val < nextA->val) {
        current->next = nextB;
        current = current->next;
        if (nextB != nullptr)
          nextB = nextB->next;
      }
      else {
        current->next = nextA;
        current = current->next;

        if (nextA != nullptr)
          nextA = nextA->next;
      }
    }

    if (nextA != nullptr)
      current->next = nextA;
    if (nextB != nullptr)
      current->next = nextB;

    return head;
  }

  int removeDuplicates(std::vector<int>& nums) {
    auto it = nums.begin() + 1;
    while (it != nums.end()) {
      auto prev = it - 1;
      if (*it != *prev) {
        ++it;
        continue;
      }

      it = nums.erase(it);
    }

    return nums.size();
  }

  std::vector<int> plusOne(std::vector<int>& vec) {
    auto it = vec.end() - 1;
    while (*it == 9 && it != vec.begin()) {
      *it = 0;
      --it;
    }

    if (it == vec.begin() && *it == 9) {
      *it = 0;
      vec.insert(it, 1);
    } else {
      (*it)++;
    }

    return vec;
  }

  int climbStairs(int n) {
    std::vector<int> dp{1, 1};
    for (int i = 2; i <= n; ++i) {
      dp.push_back(dp[i - 2] + dp[i - 1]);
    }

    return dp[n];
  }

  void merge(std::vector<int>& nums1, const int& m, const std::vector<int>& nums2, const int& n) {
    std::vector<int> sub1(nums1.begin(), nums1.begin() + m);
    std::vector<int> sub2(nums2.begin(), nums2.begin() + n);
    for (const int& v : nums2)
      sub1.push_back(v);

    std::sort(sub1.begin(), sub1.end());
    nums1 = sub1;
  }

  void inorderRec(std::vector<int>& values, TreeNode* current) {
    if (current == nullptr)
      return;

    inorderRec(values, current->left);
    values.push_back(current->val);
    inorderRec(values, current->right);
  }
  std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> res{};
    inorderRec(res, root);
    return res;
  }

  TreeNode* toBstRec(const std::vector<int>& values, int left, int right) {
    if (left > right)
      return nullptr;

    int pivot = (left + right) / 2;
    return new TreeNode(values[pivot], toBstRec(values, left, pivot - 1), toBstRec(values, pivot + 1, right));
  }
  TreeNode* sortedArrayToBST(const std::vector<int>& nums) {
    return toBstRec(nums, 0, nums.size() - 1);
  }

  std::vector<std::vector<int>> generate(const int& n) {
    if (n == 1)
      return {{1}};

    std::vector<std::vector<int>> res{{1}, {1, 1}};

    for (int i = 2; i < n; ++i) {
      std::vector<int> cur;
      cur.resize(i + 1);
      cur[0] = 1;
      cur[i] = 1;

      for (int j = 1; j < i; ++j) {
        cur[j] = res[i - 1][j - 1] + res[i - 1][j];
      }

      res.push_back(cur);
    }

    return res;
  }

  bool hasCycle(ListNode* head) {
    if (head == nullptr)
      return false;

    ListNode* fast = head;
    ListNode* slow = head;
    do {
      if (fast == nullptr || slow == nullptr || fast->next == nullptr || slow->next == nullptr)
        return false;

      fast = fast->next->next;
      slow = slow->next;
    } while (fast != slow);

    return true;
  }

  bool isIsomorphic(std::string s, std::string t) {
    if (s.length() != t.length())
      return false;

    std::map<char, char> hash;
    std::set<char> set;

    for (int i = 0; i < s.length(); ++i) {
      if (set.count(t[i]) == 1)
        continue;

      hash[s[i]] = t[i];
      set.insert(t[i]);
    }

    for (int i = 0; i < t.length(); ++i)
      s[i] = hash[s[i]];

    return s == t;
  }

  bool validAnagram(const std::string &a, const std::string &b) {
    if (a.length() != b.length())
      return false;

    std::map<char, int> hashA;
    std::map<char, int> hashB;

    for (char c : a) {
      if (hashA[c] == 0) {
        hashA[c] = 1;
        continue;
      }

      ++hashA[c];
    }

    for (char c : b) {
      if (hashB[c] == 0) {
        hashB[c] = 1;
        continue;
      }

      ++hashB[c];
    }

    for (char c : a) {
      if (hashA[c] != hashB[c])
        return false;
    }

    return true;
  }

  bool isSubsequence(std::string s, std::string t) {
    int j = 0;
    for (int i = 0; i < t.length() && j < s.length(); ++i) {
      if (s[j] == t[i]) {
        ++j;
      }
    }

    return j == s.length();
  }

  std::string licenceKeyFormatting(std::string& s, int k) {
    return "";
  }

  int pivotIndex(std::vector<int>& nums) {
    int leftSum = 0;
    int sum = 0;

    for (int num : nums)
      sum += num;

    for (int i = 0; i < nums.size(); ++i) {
      // nums[i] = PIVOT
      if (leftSum == sum - leftSum - nums[i])
        return i;

      leftSum += nums[i];
    }

    return -1;
  }

  std::vector<int> runningSum(std::vector<int> &nums) {
    std::vector<int> res;
    res.push_back(nums[0]);

    for (int i = 1; i < nums.size(); ++i)
      res.push_back(res[i - 1] + nums[i]);

    return res;
  }
}
