// lt101: Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val{0}, left{nullptr}, right{nullptr} {}
  TreeNode(int x) : val{x}, left{nullptr}, right{nullptr} {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val{x}, left{left}, right{right} {}
};

bool isMirror(TreeNode *p, TreeNode *q);

// Checks if a tree is symmetric.
// e.g.1          1
//             2      2
//          3    4  4   3    => mirror subtrees, is symmetric
//
// e.g.2          1
//             2      2
//          3    4  3   4    => equal subtrees, not symmetric
// the base problem is to check if left and right subtree are a mirror
// reflection, rather than if left and right subtree are the same.
bool isSymmetric(TreeNode *root) { return isMirror(root->left, root->right); }

// Checks if two trees are a mirror reflection.
bool isMirror(TreeNode *p, TreeNode *q) {
  // base cases
  if (!p && !q) return true;
  if (!p || !q) return false;
  // reduce
  return p->val == q->val && isMirror(p->left, q->right) &&
         isMirror(p->right, q->left);
}
