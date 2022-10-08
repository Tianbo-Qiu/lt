struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val{0}, left{nullptr}, right{nullptr} {}
  TreeNode(int x) : val{x}, left{nullptr}, right{nullptr} {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val{x}, left{left}, right{right} {}
};

// Checks if two trees are the same.
bool isSameTree(TreeNode *p, TreeNode *q) {
  // case 1: two nodes are both empty, no need to compare subtrees
  if (!p && !q) return true;
  // case 2: one of the nodes is empty, no need to compare subtrees
  if (!p || !q) return false;
  // case 3: further comparison on the subtress is needed
  //         compare the current nodes and subtrees
  //         eventually go to case 1 or 2
  return p->val == q->val && isSameTree(p->left, q->left) &&
         isSameTree(p->right, q->right);
}
