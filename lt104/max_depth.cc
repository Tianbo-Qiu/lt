// lt104: Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/
#include <algorithm>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val{0}, left{nullptr}, right{nullptr} {}
  TreeNode(int x) : val{x}, left{nullptr}, right{nullptr} {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val{x}, left{left}, right{right} {}
};

// Returns the max depth of a binary tree.
// The depth is defined as the number of nodes from the root node to an edge.
int maxDepth(TreeNode *root) {
  // the base case that can be reduced to
  if (!root) return 0;
  // reduce the problem
  return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
