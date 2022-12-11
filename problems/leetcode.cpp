#include "leetcode.h"

#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <bitset>

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

  bool isPalindrome(const int& x) {
    const std::string v = std::to_string(x);
    const int end = v.size() - 1;
    for (int i = 0; i < v.size() / 2; ++i) {
      if (v[i] == v[end - i])
        continue;

      return false;
    }

    return true;
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

  ListNode* removeNthFromEnd(ListNode* head, const int& n) {
    ListNode* temp = new ListNode(0, head);
    temp->next = head;

    ListNode* slow = temp;
    ListNode* fast = temp;
    for (int i = 0; i < n; ++i) {
      fast = fast->next;
    }

    while (fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }

    ListNode* del = slow->next;
    slow->next = slow->next->next;
    delete del;
    return temp->next;
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

  int removeElement(std::vector<int>& nums, const int& val) {
    for (auto it = nums.begin(); it != nums.end(); ++it) {
      if (*it != val)
        continue;

      nums.erase(it);
      --it;
    }

    return nums.size();
  }

  std::vector<std::vector<int>> permute(const std::vector<int>& nums) {
    if (nums.empty())
      return {{}};

    int first = nums[0];
    std::vector<int> rest(nums.size() - 1);
    std::copy(nums.begin() + 1, nums.end(), rest.begin());

    std::vector<std::vector<int>> permsWithoutFirst = permute(rest);
    std::vector<std::vector<int>> permsWithFirst = {};

    for (const std::vector<int>& perm : permsWithoutFirst) {
      for (int i = 0; i <= perm.size(); ++i) {
        std::vector<int> permutation(perm.size());
        std::copy(perm.begin(), perm.end(), permutation.begin());
        permutation.insert(permutation.begin() + i, first);

        permsWithFirst.push_back(permutation);
      }
    }

    return permsWithFirst;
  }

  int lengthOfLastWord(const std::string& s) {
    int count = 0;
    int end = 0;

    for (int i = s.size() - 1; i > 0; --i) {
      if (s[i] == ' ')
        continue;

      end = i;
      break;
    }

    for (; end >= 0; --end) {
      if (s[end] == ' ')
        break;

      ++count;
    }

    return count;
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

  void clearRowCol(std::vector<std::vector<int>>& matrix, const int& _col, const int& _row, std::map<std::string, bool>& map) {
    int column = static_cast<int>(matrix.size());
    int row = static_cast<int>(matrix[0].size());
    for (int c = 0; c < column; ++c) {
      std::string mv = std::to_string(c) + "-" + std::to_string(_row);
      if (matrix[c][_row] != 0 && !map[mv]) {
        map[mv] = true;
        matrix[c][_row] = 0;
      }
    }

    for (int r = 0; r < row; ++r) {
      std::string mv = std::to_string(_col) + "-" + std::to_string(r);
      if (matrix[_col][r] != 0 && !map[mv]) {
        map[mv] = true;
        matrix[_col][r] = 0;
      }
    }
  }

  void setZeroes(std::vector<std::vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty())
      return;

    std::map<std::string, bool> map{};
    int column = static_cast<int>(matrix.size());
    int row = static_cast<int>(matrix[0].size());

    for (int c = 0; c < column; ++c) {
      for (int r = 0; r < row; ++r) {
        if (matrix[c][r] == 0 && !map[std::to_string(c) + "-" + std::to_string(r)]) {
          clearRowCol(matrix, c, r, map);
        }
      }
    }
  }

  int partition(std::vector<int>& vec, int& low, int& high) {
    int pivot = vec[high];
    int i = low - 1;
    for (int j = low; j <= high; ++j) {
      if (vec[j] < pivot) {
        ++i;
        std::swap(vec[i], vec[j]);
      }
    }

    std::swap(vec[i + 1], vec[high]);
    return i + 1;
  }

  void quickSort(std::vector<int>& vec, int& low, int& high) {
    if (low < high) {
      int pi = partition(vec, low, high);
      int before = pi - 1;
      int after = pi + 1;
      quickSort(vec, low, before);
      quickSort(vec, after, high);
    }
  }

  void sortColors(std::vector<int>& nums) {
    int start = 0;
    int end = static_cast<int>(nums.size()) - 1;
    quickSort(nums, start, end);
  }

  void helper_combine(std::vector<std::vector<int>>& result, std::vector<int>& solution, int n, int k, int start) {
    if (solution.size() == k) {
      result.push_back(solution);
      return;
    }

    for (int i = start; i <= n; ++i) {
      solution.push_back(i);
      helper_combine(result, solution, n, k, i + 1);
      solution.pop_back();
    }
  }

  std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> result{};
    std::vector<int> solution{};
    helper_combine(result, solution, n, k, 1);

    return result;
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

  void removeNonAlphaNumeric(std::string& s) {
    s.erase(std::remove_if(s.begin(), s.end(), [] (char c) {
      return !std::isalnum(c);
    }), s.end());
  }
  bool isPalindrome(std::string& s) {
    bool escape = false;
    removeNonAlphaNumeric(s);

    if (s.empty() || s.length() == 1)
      return true;

    int left = 0;
    int right = static_cast<int>(s.length() - 1);
    while (left < right) {
      if (tolower(s[left]) != tolower(s[right]))
        return false;

      ++left;
      --right;
      escape = true;
    }

    return escape;
  }

  int singleNumber(std::vector<int>& nums) {
    int res = 0;
    for (int element : nums)
      res ^= element;

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

  ListNode* getIntersectionNode(ListNode* a, ListNode* b) {
    std::map<ListNode*, int> map;
    while (a != nullptr) {
      map[a] = 1;
      a = a->next;
    }

    while (b != nullptr) {
      if (map[b] == 1)
        return b;

      b = b->next;
    }

    return nullptr;
  }

  int majorityElement(std::vector<int>& nums) {
    int max = INT_MIN;
    int result;
    std::map<int, int> counts;
    for (const int& v : nums) {
      int k = ++counts[v];

      if (k > max) {
        result = v;
        max = k;
      }
    }

    return result;
  }

  int titleToNumber(const std::string& columnTitle) {
    std::map<char, int> map = {
        {'A', 1},
        {'B', 2},
        {'C', 3},
        {'D', 4},
        {'E', 5},
        {'F', 6},
        {'G', 7},
        {'H', 8},
        {'I', 9},
        {'J', 10},
        {'K', 11},
        {'L', 12},
        {'M', 13},
        {'N', 14},
        {'O', 15},
        {'P', 16},
        {'Q', 17},
        {'R', 18},
        {'S', 19},
        {'T', 20},
        {'U', 21},
        {'V', 22},
        {'W', 23},
        {'X', 24},
        {'Y', 25},
        {'Z', 26},
    };

    double res = 0;
    int n = static_cast<int>(columnTitle.length()) - 1;
    for (int i = 0; i <= n; ++i)
      res += std::pow(26, i) * map[columnTitle[n - i]];

    return static_cast<int>(res);
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

  uint32_t reverseBits(uint32_t n) {
    std::bitset<32> x(n);
    int size = x.size() - 1;
    int len = size / 2;
    for (int i = 0; i <= len; ++i) {
      bool tmp = x[i];
      bool right = x[size - i];
      x[size - i] = tmp;
      x[i] = right;
    }

    return x.to_ulong();
  }

  int hammingWeight(uint32_t n) {
    // manual solution
    std::bitset<32> x(n);
    int res = 0;
    unsigned int sum = 0;
    for (int i = 0; i < x.size(); ++i) {
      if (sum >= n)
        break;

      if (x[i] != 1)
        continue;

      res += 1;
      sum += static_cast<unsigned int>(pow(2, i));
    }

    return res;

    // another solution;
    // return bitset<32>(n).count(); // returns count of ones

    // improved version; O(1)
    // uint32_t n = 11;
    // int count = 0;
    // while (n) {
    //   std::cout << n << std::endl;
    //   n &= (n - 1);
    //   ++count;
    // }
  }

  bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
      return true;

    ListNode* current = head;
    std::vector<ListNode*> nodes;
    while (current != nullptr) {
      nodes.push_back(current);
      current = current->next;
    }

    bool escape = false;
    int left = 0;
    int right = static_cast<int>(nodes.size() - 1);
    while (left <= right) {
      if (nodes[left]->val != nodes[right]->val)
        return false;

      ++left;
      --right;
      escape = true;
    }

    return escape;
  }

  void deleteNode(ListNode* node) {
    ListNode* next = node->next;
    *node = *next;
    delete next;
  }

  std::vector<int> dfv(TreeNode* root) {
    std::vector<int> res{};
    if (root == nullptr)
      return res;

    std::stack<TreeNode*> stack;
    stack.push(root);
    while(!stack.empty()) {
      TreeNode* top = stack.top();
      res.push_back(top->val);
      stack.pop();

      if (top->right != nullptr)
        stack.push(top->right);
      if (top->left != nullptr)
        stack.push(top->left);
    }

    std::sort(res.begin(), res.end());
    return res;
  }

  int kthSmallest(TreeNode* root, const int& k) {
    std::vector<int> values = dfv(root);
    return values[k - 1];
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

  int missingNumber(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    int expectedSum = (n * (n + 1)) / 2;
    int sum = 0;
    for (const int& e : nums)
      sum += e;

    return expectedSum - sum;
  }

  void moveZeroes(std::vector<int>& nums) {
    int zeros = 0;
    auto it = nums.begin();
    while (it != nums.end()) {
      if (*it == 0) {
        it = nums.erase(it);
        ++zeros;
        continue;
      }

      ++it;
    }

    while (zeros > 0) {
      nums.push_back(0);
      --zeros;
    }
  }

  bool isPowerOfThree(int& n) {
    if (n < 1)
      return false;

    while (n > 1) {
      if (n % 3 != 0)
        return false;

      n /= 3;
    }

    return true;
  }

  void reverseString(std::vector<char>& s) {
    int len = s.size();
    for (int i = 0; i < len / 2; ++i)
      std::swap(s[i], s[len - i - 1]);
  }

  struct pairGreater {
    bool operator() (const std::pair<int, int>& a, const std::pair<int, int>& b) {
      return a.second < b.second;
    }
  };

  std::vector<int> topKFrequent(const std::vector<int>& nums, const int& k) {
    std::vector<int> result(k);
    std::unordered_map<int, int> map{};
    for (const int& n : nums) {
      map[n]++;
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, pairGreater> queue;
    for (const auto& kvp : map) {
      queue.push(kvp);
    }

    for (int i = 0; i < k; ++i) {
      result[i] = queue.top().first;
      queue.pop();
    }

    return result;
  }

  std::vector<int> intersect(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::vector<int> res;
    std::map<int, int> map;
    for (const int& n : nums1) {
      if (map[n]) {
        ++map[n];
        continue;
      }

      map[n] = 1;
    }

    for (const int& n : nums2) {
      if (map[n] > 0) {
        --map[n];
        res.push_back(n);
      }
    }

    return res;
  }

  int firstUniqChar(const std::string& s) {
    std::unordered_map<char, int> map;
    for (const char& c : s) {
      if (map[c]) {
        ++map[c];
        continue;
      }

      map[c] = 1;
    }

    for (int i = 0; i < s.length(); ++i) {
      if (map[s[i]] == 1)
        return i;
    }

    return -1;
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

  std::vector<std::string> fizzBuzz(const int& n) {
    std::vector<std::string> res(n);
    for (int i = 1; i <= n; ++i) {
      std::string val;
      if (i % 3 == 0 && i % 5 == 0)
        val = "FizzBuzz";
      else if (i % 3 == 0)
        val = "Fizz";
      else if (i % 5 == 0)
        val = "Buzz";
      else
        val = std::to_string(i);

      res[i - 1] = val;
    }

    return res;
  }

  std::string licenseKeyFormatting(std::string& s, int k) {
    return "";
  }

  int island_dfs(std::vector<std::vector<int>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
      return 0;

    if (grid[i][j] == 0)
      return 0;

    grid[i][j] = 0;

    int count = 1;
    count += island_dfs(grid, i + 1, j);
    count += island_dfs(grid, i - 1, j);
    count += island_dfs(grid, i, j + 1);
    count += island_dfs(grid, i, j - 1);

    return count;
  }

  int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
    int max = 0;

    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        max = std::max(island_dfs(grid, i, j), max);
      }
    }

    return max;
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
