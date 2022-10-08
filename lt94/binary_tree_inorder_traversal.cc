// lt94: Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/
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

/**
 * Inorder traversal.
 * Visists the left node, root, and right node in sequence.
 * If the left node and/or the right node is actually a tree, traverse that tree
 * in the same order.
 * in-order: current node is in the left and the right: left, current, right
 */
void traverse(TreeNode *root, std::vector<int> &res) {
  // traverse the left tree in the same order if exists
  if (root->left) traverse(root->left, res);
  // traverse the current root node
  res.push_back(root->val);
  // traverse the right tree in the same order if exists
  if (root->right) traverse(root->right, res);
}

/**
 * Returns the inorder traversal of a binary search tree.
 */
std::vector<int> inorderTraversal(TreeNode *root) {
  std::vector<int> res;
  if (root) traverse(root, res);
  return res;
}
