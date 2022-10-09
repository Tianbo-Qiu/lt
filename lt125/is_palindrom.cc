// lt125: Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/
#include <cctype>
#include <string>

// Checks if all non-alphanumeric characters in a string
// can be a palindrome (case-insensitive).
// e.g. "A b$a" => "aba", is palindrome
bool isPalindrome(std::string s) {
  int i = 0, j = s.size() - 1;
  while (i < j) {
    // find the characters to compare
    while (i < j && !std::isalnum(s[i])) ++i;
    while (i < j && !std::isalnum(s[j])) --j;
    // check and advance characters at the same time
    // since we should see every character only once
    // advance i and j at the same time, same speed (by 1) in a loop
    if (std::tolower(s[i++]) != std::tolower(s[j--])) return false;
  }
  return true;
}
