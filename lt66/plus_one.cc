// lt66: Plus One
// https://leetcode.com/problems/plus-one/
#include <vector>

// Given an integer represented as an array where digits are
// ordered from the most significant to the least, returns
// an array representing that integer plus one.
// The input is not modified.
std::vector<int> plusOne(std::vector<int>& digits) {
  std::vector<int> res;
  int carry = 1;
  for (int i = digits.size() - 1; i >= 0; --i) {
    int sum = carry + digits[i];
    carry = sum / 10;
    res.insert(res.begin(), sum % 10);
  }
  if (carry) res.insert(res.begin(), carry);
  return res;
}
