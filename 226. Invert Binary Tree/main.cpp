#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {  // 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
 public:
  void travPost_R(TreeNode* x, TreeNode* visit) {  //后序遍历，递归
    if (!x) return;
    travPost_R(x->left, visit);
    travPost_R(x->right, visit);
    visit(x->data);
  }

  TreeNode* invertTree(TreeNode* root) {
    TreeNode* result = new TreeNode();

    travPost_R(root->right, result);

    return result;
  }
};

int main() {
  return 0;
}