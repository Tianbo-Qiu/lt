// lt112: Path Sum
// https://leetcode.com/problems/path-sum/
#include "../lib/tree_node.h"

// Checks there is a path from the root node to a leaf node
// that sums to the target value.
bool hasPathSum(TreeNode *root, int targetSum) {
  // root = nullptr, targetSum = 0 is considered as false
  if (!root) return false;
  if (!root->left && !root->right) return root->val == targetSum;
  return hasPathSum(root->left, targetSum - root->val) ||
         hasPathSum(root->right, targetSum - root->val);
}
