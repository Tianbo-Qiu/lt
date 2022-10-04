// lt35: Search Insert Position
// https://leetcode.com/problems/search-insert-position/
#include <vector>

// Given a sorted array of distinct numbers in ascending order,
// returns the index to insert `target` before that keeps the array sorted.
// e.g. [1, 3, 5, 6], target 5 => 2 (insert before 5)
//      [1, 3, 5, 6], target 2 => 1 (insert before 3)
//      [1, 3, 5, 6], target 1 => 0 (insert before 1)
//      [1, 3, 5, 6], target 0 => 0 (insert before 1)
//      [1, 3, 5, 6], target 7 => 4 (after all elements, return length)
//      assuming there is no duplicate, otherwise, we need to consider the case
//      [1, 3, 5, 5, 6], target 5 => return 2 or 3?
int searchInsert(std::vector<int>& nums, int target) {
  // finds a range [0, element] where all elements are less than target
  // then the insert position will be end + 1
  int start = 0, end = nums.size() - 1;
  // while there is an element in the range
  while (start <= end) {
    // "mid": the point is to keep the length of the left half and the right
    // half almost the same (at most off by one). and try to drop one half every
    // time to perform the search in log(n) time
    int mid = (start + end) / 2;
    // check if nums[mid] is the element we are looking for
    if (nums[mid] >= target)
      // [mid...] are all larger than target as well, so element must in the
      // left half [start, mid - 1], dropped the right half
      // we only update the end in this case
      end = mid - 1;
    else
      // is there a larger element in the right half [mid+1...] so that we can
      // update `end` again? it's ok if we don't find one in [mid+1...] since we
      // only update `start` here. dropped the left half
      start = mid + 1;  // the loop won't end if start = mid
  }
  return end + 1;
}
