// lt108: Convert Sorted Array to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val{0}, left{nullptr}, right{nullptr} {}
  TreeNode(int x) : val{x}, left{nullptr}, right{nullptr} {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val{x}, left{left}, right{right} {}
};

TreeNode *sortedArrayToBST(std::vector<int> &nums, int start, int end);

// Converts a sorted array to a height-balanced binary tree.
// A height-balanced binary tree is a tree in which the depth of the
// two subtrees of every node never differs by more than one.
// so for [1, 2, 3] the root should be 2, the middle point
//        2
//    1      3
// for [1, 2, 3, 4] the root can be 2 or 3, also  the middle point
//       2                3
//    1    3           2     4
//           4      1
// we need to be consistent though, if we choose to put one more node on the
// left we should do the same for all substrees.
TreeNode *sortedArrayToBST(std::vector<int> &nums) {
  return sortedArrayToBST(nums, 0, nums.size());
}

// Converts a sorted array from a half-close range [start, end) to a binary
// search tree.
TreeNode *sortedArrayToBST(std::vector<int> &nums, int start, int end) {
  TreeNode *node = nullptr;
  if (start < end) {  // if there is still a node to convert
    // this will always leave one more node on the right when the length is even
    int mid = (start + end) / 2;
    node = new TreeNode(nums[mid]);
    // get left subtree from [start, mid)
    node->left = sortedArrayToBST(nums, start, mid);
    // get right subtree from [mid + 1, end)
    node->right = sortedArrayToBST(nums, mid + 1, end);
  }
  return node;
}
