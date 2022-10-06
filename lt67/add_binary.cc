// lt67: Add Binary
// https://leetcode.com/problems/add-binary/
#include <string>

// Returns the sum of two binary numbers in strings.
std::string addBinary(std::string a, std::string b) {
  int carry = 0;
  std::string res;
  auto p1 = a.crbegin();
  auto p2 = b.crbegin();
  while (p1 != a.crend() || p2 != b.crend() || carry) {
    int sum = carry;
    if (p1 != a.crend()) {
      sum += *p1 - '0';  // converts '1' to 1 and '0' to 0
      ++p1;
    }
    if (p2 != b.crend()) {
      sum += *p2 - '0';
      ++p2;
    }
    res = std::to_string(sum % 2) + res;
    carry = sum / 2;
  }
  return res;
}
