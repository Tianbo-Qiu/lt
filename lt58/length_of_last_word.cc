// lt58: Length of Last Word
// https://leetcode.com/problems/length-of-last-word/
#include <string>

// Returns the length of the last word in a string.
// A word is a maximal substring consisting of non-space characters.
// e.g. " Hello World  " => "World" => 5
int lengthOfLastWord(std::string s) {
  // scan from right to left
  int i = s.size() - 1;
  // remove trailing spaces, stop at the first non-space character
  // remember to check i>=0 in the while loop
  while (i >= 0 && s[i] == ' ') --i;
  // counting until the next space
  int len = 0;
  while (i >= 0 && s[i] != ' ') {
    --i;
    ++len;
  }
  return len;
}
