// lt27: Remove Element
// https://leetcode.com/problems/remove-element/
#include <vector>

/**
 * Rearranges the array in place so that the first `k` elements
 * don't equal to `val` and elements after those can be anything.
 * Returns `k`: the number of elements that don't equal to `val`.
 * The relative order is kept in the first `k` elements.
 * e.g. [3, 2, 1, 2, 3], val = 3 =>  [2, 1, 2, any, any], k = 3
 */
int removeElement(std::vector<int>& nums, int val) {
  // the number of valid elements (not euqal to `val`)
  int len = 0;
  // check one by one
  for (int num : nums)
    // if valid, put it to the available place (index `len`) and update length
    if (num != val) nums[len++] = num;
  return len;
}
