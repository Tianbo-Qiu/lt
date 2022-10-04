// lt26: Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include <vector>

// Given a non-descresing list, rearranges the list in place so that the
// first `k` elements are unique and in ascending order. Numbers after `k`
// can be anything and will be ignored.
// Returns `k`: the number of elements that are unique.
// e.g. [1, 1, 2] => [1, 2, any], k = 2
int removeDuplicates(std::vector<int>& nums) {
  // the number of unique elements
  int len = 0;
  // check number in list one by one
  for (int num : nums) {
    // found one: either the fist number or a number larger than the last one
    if (len == 0 || num > nums[len - 1]) {
      // place the number and update the length of unique elements
      nums[len] = num;
      ++len;
    }
  }
  return len;
}
