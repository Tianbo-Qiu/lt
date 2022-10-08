// lt88: Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/
#include <vector>

// Given two sorted array in non-descresing order, merge the second array
// (length n) into the first one (length m + n).
// e.g. [1, 2, 3, 0, 0, 0], m = 3
//      [2, 5, 6], n = 3
//    =>[1, 2, 2, 3, 5, 6]
void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
  int p1 = m - 1;     // the last (biggest) element of nums1
  int p2 = n - 1;     // the last (biggest) element of nums2
  int i = m + n - 1;  // points to the biggest remaining element
  while (p2 >= 0) {   // while we still need to merge from nums2
    if (p1 >= 0 && nums1[p1] >= nums2[p2])
      // p1 points to the biggest, advance i and p1
      nums1[i--] = nums1[p1--];
    else
      // p2 points to the biggest, advance i and p2
      nums1[i--] = nums2[p2--];
  }
}
