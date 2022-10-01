// lt 9: Palindrome Number
// https://leetcode.com/problems/palindrome-number/
#include <cmath>

// Checks if an integer is a palindrome.
// A number is considered as a palindrome if it's a non-negative number
// and reads the same backward as forward.
bool isPalindrome(int x) {
  if (x < 0) return false;

  // reverse half of the number and compare
  // log10(0) is -Inf
  int len = x == 0 ? 1 : log10(x) + 1;
  int rev = 0;
  for (int i = 0; i < len / 2; ++i) {
    rev = 10 * rev + x % 10;
    x /= 10;
  }

  // we skipped the middle number when len(x) is odd
  return len % 2 ? rev == x / 10 : rev == x;
}
