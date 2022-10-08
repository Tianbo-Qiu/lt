// lt110: Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/
#include <algorithm>
#include <cmath>

#include "../lib/tree_node.h"

int balancedHeight(TreeNode *root);

// Given a binary tree, checks if the tree is height-balanced.
// A binary tree is balanced if the left and right subtrees of every node
// differ in height at most by 1.
bool isBalanced(TreeNode *root) { return balancedHeight(root) != -1; }

// If a tree is balanced, returns the height of the tree.
// Otherwise, returns -1.
int balancedHeight(TreeNode *root) {
  if (!root) return 0;
  // visits every node only once
  int left = balancedHeight(root->left);
  int right = balancedHeight(root->right);
  // tree is not balanced, returns -1 to denote it
  if (left == -1 || right == -1 || std::abs(left - right) > 1) return -1;
  // tree is balanced, returns the actual height
  return std::max(left, right) + 1;
}
