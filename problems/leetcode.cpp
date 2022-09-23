#include "leetcode.h"

#include <map>
#include <set>

namespace algo {

bool leetcode::isIsomorphic(std::string s, std::string t) {
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
}
