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

  bool isBadVersion (int version) { return version % 2; }
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

  bool validateRecursive(TreeNode* root, const long& leftBoundary, const long& rightBoundary) {
    if (root == nullptr)
      return true;

    if (!(root->val > leftBoundary && root->val < rightBoundary))
      return false;

    return validateRecursive(root->left, leftBoundary, root->val) && validateRecursive(root->right, root->val, rightBoundary);
  }
  bool isValidBST(TreeNode* root) {
    if (root->left == nullptr && root->right == nullptr)
      return true;

    return validateRecursive(root, LONG_MIN, LONG_MAX);
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    std::vector<TreeNode*> desP;
    std::vector<TreeNode*> desQ;

    TreeNode* current = root;
    while (current != nullptr) {
      desP.push_back(current);
      if (current->val > p->val) {
        current = current->left;
      }
      else if (current->val < p->val) {
        current = current->right;
      }
      else {
        break;
      }
    }

    current = root;
    while (current != nullptr) {
      desQ.push_back(current);
      if (current->val > q->val) {
        current = current->left;
      }
      else if (current->val < q->val) {
        current = current->right;
      }
      else {
        break;
      }
    }

    int len = std::min(desP.size(), desQ.size());
    for (int i = 0; i < len; ++i) {
      if (desP[i] == desQ[i])
        continue;

      return desP[i - 1];
    }

    return desP.size() < desQ.size()
      ? desP[desP.size() - 1]
      : desQ[desQ.size() - 1];
  }

  void floodRecursive(std::vector<std::vector<int>>& image, const int& x, const int& y, const int& color, const int& oldColor) {
    if (x < 0 || x >= image.size() || y < 0 || y >= image[x].size())
      return;
    if (image[x][y] != oldColor)
      return;

    image[x][y] = color;

    floodRecursive(image, x, y - 1, color, oldColor);
    floodRecursive(image, x, y + 1, color, oldColor);
    floodRecursive(image, x - 1, y, color, oldColor);
    floodRecursive(image, x + 1, y, color, oldColor);
  }
  std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, const int& sr, const int& sc, const int& color) {
    if (image[sr][sc] == color)
      return image;

    int oldColor = image[sr][sc];
    floodRecursive(image, sr, sc, color, oldColor);

    return image;
  }

  bool islandRecursive(std::vector<std::vector<char>>& grid, const int& x, const int& y, int& count) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
      return false;
    if (grid[x][y] == '0')
      return false;

    grid[x][y] = '0';
    bool top = islandRecursive(grid, x, y - 1, count);
    bool bottom = islandRecursive(grid, x, y + 1, count);
    bool left = islandRecursive(grid, x - 1, y, count);
    bool right = islandRecursive(grid, x + 1, y, count);

    return !(top && bottom && left && right);
  }
  int numIslands(std::vector<std::vector<char>>& grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        count += islandRecursive(grid, i, j, count);
      }
    }

    return count;
  }

  int fib(const int& n) {
    if (n == 0 || n == 1)
      return n;

    int prev1 = 0;
    int prev2 = 1;
    int res;

    for (int i = 2; i <= n; ++i) {
      res = prev1 + prev2;
      prev1 = prev2;
      prev2 = res;
    }

    return res;
  }

  int climbStairs(const int& n) {
    std::vector<int> dp{1, 1};
    for (int i = 2; i <= n; ++i)
      dp.push_back(dp[i - 1] + dp[i - 2]);

    return *(dp.end() - 1);
  }

  int minCostClimbingStairs(std::vector<int>& vec) {
    int len = vec.size();
    if (len == 1)
      return vec[0];

    int cost;
    for (int i = len - 3; i >= 0; --i) {
      cost = std::min(vec[i + 2], vec[i + 1]);
      vec[i] += cost;
    }

    return std::min(vec[0], vec[1]);
  }

  int uniquePaths(const int& m, const int& n) {
    std::vector<std::vector<int>> vec{{1}};
    int top, left;
    for (int i = 0; i < m; ++i) {
      vec.emplace_back();
      for (int j = 0; j < n; ++j) {
        if (i == 0 && j == 0)
          continue;

        top = i < 1 ? 0 : vec[i - 1][j];
        left = j < 1 ? 0 : vec[i][j - 1];

        vec[i].push_back(top + left);
      }
    }

    return vec[m - 1][n - 1];
  }

  std::vector<int> findAnagrams(const std::string& s, const std::string& p) {
    std::vector<int> res;

    std::map<char, int> mapP;
    std::map<char, int> mapS;

    for (const char& c : p) {
      if (mapP[c]) {
        ++mapP[c];
        continue;
      }

      mapP[c] = 1;
    }

    char left;
    char right;
    int lenP = p.length();
    for (int i = 0; i < s.size() - lenP + 1; ++i) {
      std::string sub = s.substr(i, lenP);

      left = s[i];
      right = s[i + lenP];
    }

    return res;
  }

  std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::vector<int> res;
    std::unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
      if (!(map.find(target - nums[i]) != map.end())) {
        map.insert(std::pair(nums[i], i));
        continue;
      }

      res.push_back(map[target - nums[i]]);
      res.push_back(i);
      break;
    }

    return res;
  }

  bool backspaceCompare(const std::string& s, const std::string& t) {
    std::stack<char> sStack;
    std::stack<char> tStack;

    for (const char& c : s) {
      if (!sStack.empty() && c == '#')
        sStack.pop();
      else if (c != '#')
        sStack.push(c);
    }

    for (const char& c : t) {
      if (!tStack.empty() && c == '#')
        tStack.pop();
      else if (c != '#')
        tStack.push(c);
    }

    return sStack == tStack;
  }
}






















