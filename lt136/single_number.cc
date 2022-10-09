// lt136: Single Number
// https://leetcode.com/problems/single-number/
#include <vector>

// Returns the single number in the array where every number appears twice
// except for one.
int singleNumber(std::vector<int>& nums) {
  // exclusive or operation
  // a xor 0 = a
  // a xor a = 0
  // a xor b xor a = a xor a xor b = b
  int res = 0;
  for (int num : nums) res ^= num;
  return res;
}
