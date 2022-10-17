

#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int rangeSumBST(TreeNode *root, int low, int high) {
    if (root == nullptr) {
      return 0;
    }
    if (root->val > high) {
      return rangeSumBST(root->left, low, high);
    }
    if (root->val < low) {
      return rangeSumBST(root->right, low, high);
    }
    return root->val + rangeSumBST(root->left, low, high) +
           rangeSumBST(root->right, low, high);
  }
};

int main() {
  using namespace std;
  const char *a = "A B C D E F x x x G H x I";
  int low = 7;
  int high = 15;
  return 0;
}