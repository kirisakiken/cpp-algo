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
  std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, std::vector<int>> map{};
    map[nums[0]] = {0};

    for (int i = 1; i < nums.size(); ++i) {
      int val = nums[i];
      int rem = target - val;
      if (map.find(rem) != map.end()) {
        return {map[rem][0], i};
      }

      if (map.find(val) != map.end()) {
        map[val].push_back(i);
        continue;
      }

      map[val] = {i};
    }

    return {};
  }

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

  int maxArea(const std::vector<int>& height) {
    int mx = 0, l = 0, r = static_cast<int>(height.size()) - 1;
    while (l < r) {
      int mxv = std::min(height[l], height[r]) * (r - l);
      if (mxv > mx)
        mx = mxv;

      if (height[l] > height[r])
        --r;
      else
        ++l;
    }

    return mx;
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

  // Python solution (numpy);
  /*
   * class Solution:
        def _isUnique(self, collection):
            mp: Dict[str, int] = {}
            for e in collection:
                if mp.get(e) is None:
                    mp[e] = 1
                    continue
                mp[e] += 1

            for key, value in mp.items():
                if key == '.':
                    continue

                if value > 1:
                    return False
            return True
        def _validateCell(self, cell) -> bool:
            return self._isUnique(cell)
        def _validateCol(self, col) -> bool:
            return self._isUnique(col)
        def _validateRow(self, row) -> bool:
            return self._isUnique(row)

        def isValidSudoku(self, board: List[List[str]]) -> bool:
            arr = np.array(board)
            for i in range(0, 9, 3):
                for j in range(0, 9, 3):
                    if not self._validateCell(arr[i:i+3, j:j+3].flatten()):
                        return False

            for i in range(9):
                if not self._validateCol(arr[i:i+1].flatten()):
                    return False

                if not self._validateRow(arr[:, i:i+1].flatten()):
                    return False

            return True
   */
  bool isValidSudoku(const std::vector<std::vector<char>>& board) {
    return NAN;
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

  void rotate(std::vector<std::vector<int>>& matrix) {
    // reverse
    std::reverse(matrix.begin(), matrix.end());

    // swap i,j <> j,i
    int size = static_cast<int>(matrix.size());
    for (int i = 0; i < size; ++i)
    for (int j = i + 1; j < size; ++j)
      std::swap(matrix[i][j], matrix[j][i]);
  }

  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::map<std::string, std::vector<std::string>> map;
    for (const std::string& s : strs) {
      std::string tmp = s;
      std::sort(tmp.begin(), tmp.end());

      map[tmp].push_back(s);
    }

    std::vector<std::vector<std::string>> res;
    res.reserve(map.size());
    for (const auto& kvp : map)
      res.push_back(kvp.second);

    return res;
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

  int binFind(const std::vector<int>& vec, const int& target, int left, int right) {
    if (vec.empty() || left > right)
      return -1;

    int pivot = (left + right) / 2;
    if (vec[pivot] < target)
      return binFind(vec, target, pivot + 1, right);
    else if (vec[pivot] > target)
      return binFind(vec, target, left, pivot - 1);

    return pivot;
  }
  int getCol(const std::vector<std::vector<int>>& mat, const int& target, int left, int right) {
    if (left > right)
      return -2;

    int pivot = (left + right) / 2;
    int lval = mat[pivot][0], rval = mat[pivot][mat[pivot].size() - 1];

    if (target == lval || target == rval)
      return -1;

    if (target < lval)
      return getCol(mat, target, left, pivot - 1);
    else if (target > rval)
      return getCol(mat, target, pivot + 1, right);
    else
      return pivot;
  }
  bool searchMatrix(const std::vector<std::vector<int>>& matrix, const int& target) {
    if (matrix.empty() || matrix[0].empty())
      return false;

    int targetCol = getCol(matrix, target, 0, static_cast<int>(matrix.size()) - 1);
    if (targetCol == -1)
      return true;
    else if (targetCol == -2)
      return false;

    return binFind(matrix[targetCol], target, 0, static_cast<int>(matrix[targetCol].size()) - 1) != -1;
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

  std::vector<std::vector<int>> subsets(const std::vector<int>& nums) {
    if (nums.empty())
      return {{}};

    int first = nums[0];
    std::vector<int> rest(nums.size() - 1);
    std::copy(nums.begin() + 1, nums.end(), rest.begin());

    std::vector<std::vector<int>> combsWithoutFirst = subsets(rest);
    std::vector<std::vector<int>> combsWithFirst = {};

    for (const std::vector<int>& comb : combsWithoutFirst) {
      std::vector<int> combination(comb.size());
      std::copy(comb.begin(), comb.end(), combination.begin());
      combination.push_back(first);

      combsWithFirst.push_back(combination);
    }

    std::vector<std::vector<int>> result{};
    result.insert(result.end(), combsWithoutFirst.begin(), combsWithoutFirst.end());
    result.insert(result.end(), combsWithFirst.begin(), combsWithFirst.end());

    return result;
  }

  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr)
      return nullptr;

    ListNode* current = head;
    while (current->next != nullptr) {
      if (current->val == current->next->val)
        current->next = current->next->next;
      else
        current = current->next;
    }

    return head;
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

  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr)
      return true;
    else if (p == nullptr || q == nullptr)
      return false;

    if (p->val != q->val)
      return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }

  struct TreeNodeLevel
  {
    TreeNodeLevel(TreeNode* node, int level) : node(node), level(level) {}

    TreeNode* node;
    int level;
  };
  void bfsZigzagValues(std::vector<std::vector<int>>& values, std::queue<TreeNodeLevel>& queue) {
    if (queue.empty())
      return;

    TreeNodeLevel current = queue.front();
    queue.pop();

    if (values.size() <= current.level)
      values.push_back({current.node->val});
    else {
      if (current.level % 2 == 1)
        values[current.level].insert(values[current.level].begin(), current.node->val);
      else
        values[current.level].push_back(current.node->val);
    }

    if (current.node->left != nullptr)
      queue.push(TreeNodeLevel(current.node->left, current.level + 1));
    if (current.node->right != nullptr)
      queue.push(TreeNodeLevel(current.node->right, current.level + 1));

    return bfsZigzagValues(values, queue);
  }
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (root == nullptr)
      return {};

    std::vector<std::vector<int>> result{{}};
    std::queue<TreeNodeLevel> queue;
    queue.push(TreeNodeLevel(root, 0));

    bfsZigzagValues(result, queue);
    return result;
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

  struct NodeGreater{
    bool operator() (const ListNode* a, const ListNode* b) {
      return a->val < b->val;
    }
  };

  ListNode* sortList(ListNode* head) {
    std::priority_queue<ListNode*, std::vector<ListNode*>, NodeGreater> queue;

    while (head != nullptr) {
      queue.push(head);
      head = head->next;
    }

    ListNode* next = nullptr;
    while (!queue.empty()) {
      ListNode* current = queue.top();
      queue.pop();

      current->next = next;
      next = current;
    }

    return next;
  }

  std::string applyRPN(const std::string& op, const std::string& a, const std::string& b) {
    int ai = std::stoi(a);
    int bi = std::stoi(b);
    switch (op[0]) {
      case '+':
        return std::to_string(ai + bi);
      case '-':
        return std::to_string(ai - bi);
      case '*':
        return std::to_string(ai * bi);
      case '/':
        return std::to_string(ai / bi);
      default:
        throw;
    }
  }
  int evalRPN(const std::vector<std::string>& tokens) {
    std::stack<std::string> stack{};
    for (const std::string& c : tokens) {
      if (c == "+" || c == "-" || c == "*" || c == "/") {
        std::string b = stack.top();
        stack.pop();
        std::string a = stack.top();
        stack.pop();

        stack.push(applyRPN(c, a, b));
        continue;
      }

      stack.push(c);
    }

    return std::stoi(stack.top());
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

  std::vector<int> _rc(const std::vector<int>& nums, const int& target, int left, int right) {
    if (left >= right)
      return {};

    int sm = nums[left] + nums[right];
    if (sm == target)
      return {left + 1, right + 1};

    if (sm > target)
      return _rc(nums, target, left, right - 1);
    else
      return _rc(nums, target, left + 1, right);

    return {};
  }
  std::vector<int> twoSum(const std::vector<int>& numbers, const int& target) {
    return _rc(numbers, target, 0, static_cast<int>(numbers.size()) - 1);
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

  int happySum(int& num) {
    int res = 0;
    while (num > 0) {
      res += (int) std::pow(num % 10, 2);
      num /= 10;
    }

    return res;
  }
  bool isHappy(int n) {
    do {
      n = happySum(n);

      if (n == 1)
        return true;
      if (n % 10 == 5)
        return false;
    } while (n > 0);

    return false;
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

  void rotate(std::vector<int>& nums, int k) {
    k %= static_cast<int>(nums.size());

    std::vector<int> first = std::vector<int>(nums.begin(), nums.end() - k);
    std::vector<int> second = std::vector<int>(nums.end() - k, nums.end());

    nums.clear();
    nums.insert(nums.end(), second.begin(), second.end());
    nums.insert(nums.end(), first.begin(), first.end());
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

  bool containsDuplicate(const std::vector<int>& nums) {
    std::unordered_map<int, int> map{};
    for (const int& n : nums) {
      if (map[n])
        return true;

      map[n] = 1;
    }

    return false;
  }

  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr)
      return nullptr;

    std::swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
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

  std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    std::vector<int> res(nums.size());
    int pre = 1;
    for (int i = 0; i < nums.size(); ++i) {
      res[i] = pre;
      pre *= nums[i];
    }

    pre = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
      res[i] *= pre;
      pre *= nums[i];
    }

    return res;
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

  ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr)
      return nullptr;

    ListNode* headA = head;
    ListNode* headB = head->next;

    ListNode* current = head;
    ListNode* next = nullptr;
    while (current->next != nullptr) {
      // save next
      next = current->next;

      // rebind current next
      current->next = next->next;

      // move current to next
      current = next;
    }

    // rebind headA <> headB
    current = headA;
    while (current->next != nullptr)
      current = current->next;
    current->next = headB;

    return headA;
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

  bool canConstruct(const std::string& ransomNote, const std::string& magazine) {
    std::unordered_map<char, int> map{};
    for (const char& c : magazine) {
      if (!map[c]) {
        map[c] = 1;
        continue;
      }

      ++map[c];
    }

    for (const char& c : ransomNote) {
      if (!map[c])
        return false;

      --map[c];
    }

    return true;
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

  std::unordered_map<char, std::string> morseLookup = {
      {'a', ".-"},
      {'b', "-..."},
      {'c', "-.-."},
      {'d', "-.."},
      {'e', "."},
      {'f', "..-."},
      {'g', "--."},
      {'h', "...."},
      {'i', ".."},
      {'j', ".---"},
      {'k', "-.-"},
      {'l', ".-.."},
      {'m', "--"},
      {'n', "-."},
      {'o', "---"},
      {'p', ".--."},
      {'q', "--.-"},
      {'r', ".-."},
      {'s', "..."},
      {'t', "-"},
      {'u', "..-"},
      {'v', "...-"},
      {'w', ".--"},
      {'x', "-..-"},
      {'y', "-.--"},
      {'z', "--.."},
  };
  std::string wordToMorseStr(const std::string& word) {
    std::string res{};
    for (const char& c : word)
      res += morseLookup[c];

    return res;
  }
  int uniqueMorseRepresentations(const std::vector<std::string>& words) {
    int res = 0;
    std::unordered_map<std::string, int> map{};
    for (const std::string& word : words) {
      std::string morse = wordToMorseStr(word);
      if (!map[morse]) {
        ++res;
        map[morse] = 1;
      }
    }

    return res;
  }

  std::vector<int> decompressRLElist(const std::vector<int>& nums) {
    std::vector<int> res{};
    for (auto it = nums.begin(); it != nums.end(); it += 2) {
      int count = *it;
      int val = *(it + 1);

      for (int i = 0; i < count; ++i)
        res.push_back(val);
    }

    return res;
  }

  std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
    std::vector<int> res{};
    for (const int& i : nums) {
      int val = 0;
      for (const int& j : nums) {
        if (i == j)
          continue;

        if (i > j)
          ++val;
      }

      res.push_back(val);
    }

    return res;
  }

  std::vector<int> createTargetArray(std::vector<int>& nums, std::vector<int>& index) {
    std::vector<int> res{};
    for (int i = 0; i < nums.size(); ++i)
      res.insert(res.begin() + index[i], nums[i]);

    return res;
  }

  std::vector<bool> kidsWithCandies(const std::vector<int>& candies, int extraCandies) {
    std::vector<bool> res{};
    int max = *(std::max_element(candies.begin(), candies.end()));
    for (const int e : candies)
      res.push_back(e + extraCandies >= max);

    return res;
  }

  std::vector<int> runningSum(std::vector<int> &nums) {
    std::vector<int> res;
    res.push_back(nums[0]);

    for (int i = 1; i < nums.size(); ++i)
      res.push_back(res[i - 1] + nums[i]);

    return res;
  }

  std::vector<int> shuffle(std::vector<int>& nums, int n) {
    std::vector<int> res{};
    std::vector<int> first(nums.begin(), nums.begin() + n);
    std::vector<int> second(nums.begin() + n, nums.end());
    for (int i = 0; i < n; ++i) {
      res.push_back(first[i]);
      res.push_back(second[i]);
    }

    return res;
  }

  int numIdenticalPairs(const std::vector<int>& nums) {
    int res = 0;

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[i] == nums[j])
          ++res;
      }
    }

    return res;
  }

  std::string restoreString(const std::string& s, const std::vector<int>& indices) {
    std::string res{};
    res.resize(indices.size());

    for (int i = 0; i < indices.size(); ++i)
      res[indices[i]] = s[i];

    return res;
  }

  int diagonalSum(const std::vector<std::vector<int>>& mat) {
    int res = 0;
    unsigned int s = 0, e = mat.size() - 1;
    for (int i = 0; i < mat.size(); ++i, ++s, --e)
      res += mat[s][i] + mat[e][i];

    if (mat.size() % 2 == 1) {
      s = mat.size() / 2;
      res -= mat[s][s];
    }

    return res;
  }

  std::string concatVec(const std::vector<std::string>& vec) {
    std::string res{};
    for (const std::string& s : vec)
      res.append(s);

    return res;
  }
  bool arrayStringsAreEqual(const std::vector<std::string>& word1, const std::vector<std::string>& word2) {
    std::string s1 = concatVec(word1);
    std::string s2 = concatVec(word2);

    return std::equal(s1.begin(), s1.end(), s2.begin(), s2.end());
  }

  int vectorSum(const std::vector<int>& vec) {
    int sum = 0;
    for (const int& e : vec)
      sum += e;

    return sum;
  }
  int maximumWealth(const std::vector<std::vector<int>>& accounts) {
    int max = 0;
    for (const auto& acc : accounts) {
      int sum = vectorSum(acc);
      if (sum > max)
        max = sum;
    }

    return max;
  }

  int getLookup(char c) {
    switch (c) {
      case 't':
        return 0;
      case 'c':
        return 1;
      case 'n':
        return 2;
      default:
        return -1;
    }
  }
  int countMatches(const std::vector<std::vector<std::string>>& items, const std::string& ruleKey, const std::string& ruleValue) {
    int res = 0;
    for (const auto& v : items) {
      int lookup = getLookup(ruleKey[0]);
      if (v[lookup] == ruleValue)
        ++res;
    }

    return res;
  }

  std::unordered_map<char, int> buildAllowedMap(const std::string& word) {
    std::unordered_map<char, int> res{};
    for (const char& c : word)
      res[c] = 1;

    return res;
  }
  int countConsistentStrings(const std::string& allowed, const std::vector<std::string>& words) {
    int res = 0;
    std::unordered_map<char, int> map = buildAllowedMap(allowed);
    for (const std::string& w : words) {
      int cnt = 0;
      for (const char& c : w) {
        if (map[c])
          ++cnt;
      }

      if (cnt == w.size())
        ++res;
    }

    return res;
  }

  std::string truncateSentence(const std::string& s, int k) {
    auto end = s.begin();
    for (const char& c : s) {
      if (c == ' ')
        --k;

      if (k == 0)
        break;

      ++end;
    }

    return std::string{s.begin(), end};
  }

  std::vector<int> buildArray(const std::vector<int>& nums) {
    std::vector<int> res{};
    for (int i = 0; i < nums.size(); ++i) {
      int targetIndex = nums[i];
      res.push_back(nums[targetIndex]);
    }

    return res;
  }

  std::vector<int> getConcatenation(std::vector<int>& nums) {
    auto size = static_cast<unsigned int>(nums.size());
    for (unsigned int i = 0; i < size; ++i) {
      nums.push_back(nums[i]);
    }

    return nums;
  }

  int countKDifference(const std::vector<int>& nums, int k) {
    int res = 0, j = 1;
    for (const int& v : nums) {
      for (int p = j; p < nums.size(); ++p) {
        if (std::abs(v - nums[p]) == k)
          ++res;
      }

      ++j;
    }

    return res;
  }

  int finalValueAfterOperations(const std::vector<std::string>& operations) {
    int res = 0;
    for (auto& op : operations) {
      int operationValue = 0;
      if (op[0] == '+' || op[2] == '+')
        operationValue = 1;
      else if (op[0] == '-' || op[2] == '-')
        operationValue = -1;

      res += operationValue;
    }

    return res;
  }

  int countWords(const std::string& str) {
    int res = 1;
    for (const auto& c : str) {
      if (c == ' ')
        ++res;
    }

    return res;
  }
  int mostWordsFound(const std::vector<std::string>& sentences) {
    int max = 0;
    for (const auto& e : sentences) {
      int ln = countWords(e);
      if (ln > max)
        max = ln;
    }

    return max;
  }

  int sumDigits(int n) {
    int res = 0;
    while (n > 0) {
      int rem = n % 10;
      n = n / 10;
      res += rem;
    }

    return res;
  }
  int differenceOfSum(const std::vector<int>& nums) {
    int sum = 0;
    int dsum = 0;
    for (const int& n : nums) {
      sum += n;
      dsum += sumDigits(n);
    }

    return abs(sum - dsum);
  }

  std::vector<int> leftRigthDifference(const std::vector<int>& nums) {
    std::vector<int> left{0};
    int sum = 0;
    for (int i = 1; i < nums.size(); ++i) {
      sum += nums[i - 1];
      left.push_back(sum);
    }

    std::vector<int> right{0};
    sum = 0;
    for (int i = nums.size() - 2; i >= 0; --i) {
      sum += nums[i + 1];
      right.insert(right.begin(), sum);
    }

    std::vector<int> res{};
    for (int i = 0; i < nums.size(); ++i) {
      res.push_back(abs(left[i] - right[i]));
    }

    return res;
  }

  int sumOfMultiples(int n) {
    int res = 0;
    for (int i = 0; i <= n; ++i)
      if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
        res += i;

    return res;
  }
}
