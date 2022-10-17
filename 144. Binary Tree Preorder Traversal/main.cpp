
#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {  // Recursive
 public:
  void traversal(TreeNode *cur, vector<int> &vec) {
    if (cur == nullptr) {  // 如果节点cur为空
      return;
    }
    vec.push_back(cur->val);     // 中
    traversal(cur->left, vec);   // 左
    traversal(cur->right, vec);  // 右
  }
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> result;  // 储存遍历元素的向量
    traversal(root, result);
    return result;
  }
};

void CreatBiTree(TreeNode *&T) {  // 先序递归创建二叉树
  // 先按顺序驶入二叉树中节点的值(一个字符),空格字符代表空树
  char ch;
  for (int j = 0; j < 13; ++j) {
    if ((ch = getchar()) == '#')
      T = nullptr;
    else {
      T = new TreeNode;       // 产生新的子树
      T->val = ch;            // 由getchar()逐个读进来
      CreatBiTree(T->left);   // 递归创建左子树
      CreatBiTree(T->right);  // 递归创建右子树
    }
  }
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = nullptr;
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);

  Solution solve;
  vector<int> result = solve.preorderTraversal(root);
  for (const auto &elem : result) {
    cout << elem << " ";
  }

  return 0;
}