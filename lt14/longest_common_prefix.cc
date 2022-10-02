// lt14: Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/

#include <string>
#include <vector>

// Returns the longest common prefix of the strings.
// e.g.
// s1: abcde
// s2: abc
// s3: abcbb
// s4: abcbd
// res => "abc"
std::string longestCommonPrefix(std::vector<std::string>& strs) {
  std::string prefix;
  if (strs.empty()) return prefix;
  if (strs.size() == 1) return strs[0];
  // compare the character at index `i` of all the strings one by one
  // e.g. check other strings against characters in s1:
  //      scan a: check s2, s3, s4 (pass) => found prefix "a"
  //      scan b: check s2, s3, s4 (pass) => found prefix "ab"
  //      scan c: check s2, s3, s4 (pass) => found perfix "abc"
  //      scan d: check s2 (fail)         => return perfix "abc"
  //      we will visit all characters in strs at most once so the time
  //      complexity is O(S) where S is the total number of characters in strs
  //      or O(min(len) * size of (strs))
  for (int i = 0; i < strs[0].size(); ++i) {
    // compare other strings against the first string
    for (int j = 1; j < strs.size(); ++j) {
      // fail, return the longest prefix
      if (strs[j].size() < i + 1 || strs[j][i] != strs[0][i]) return prefix;
    }
    // pass, extend prefix
    prefix += strs[0][i];
  }
  return prefix;
}
