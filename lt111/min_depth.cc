// lt111: Minimum Depth of Binary Tree
// https://leetcode.com/problems/minimum-depth-of-binary-tree/
#include <algorithm>

#include "../lib/tree_node.h"

// Returns the minimum depth from the root to a leaf node.
// e.g.        3
//          9     20
//             15     7
//    the shortest path is 3 -> 9 so the minDepth is 2
//             3
//                20
//             15
//    the shortest path is 3 -> 20 -> 15 instead of 3 itself.
//    and the minDepth is 3 rather than 1.
int minDepth(TreeNode* root) {
  if (!root) return 0;
  // find the min depth of every node  if (!root) return 0;
  int left = minDepth(root->left);
  int right = minDepth(root->right);
  // if one of the subtree is empty, return the height of the other plus one
  if (left == 0 || right == 0) return std::max(left, right) + 1;
  // if both are non-empty, return the min height of them plus one
  return std::min(left, right) + 1;
}
