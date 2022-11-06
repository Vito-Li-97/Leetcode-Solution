
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  // 给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。
  //（即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 public:
  // 方法一：BFS
  // O(n);
  // O(n);
  // bfs 输出结果时层次逆序
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr) {
      return res;
    }

    queue<TreeNode *> qt;
    qt.push(root);

    while (!qt.empty()) {
      vector<int> cache;
      int qts = qt.size();

      for (int i = 0; i < qts; i++) {
        root = qt.front();
        qt.pop();
        cache.push_back(root->val);
        if (root->left != nullptr) {
          qt.push(root->left);
        }
        if (root->right != nullptr) {
          qt.push(root->right);
        }
      }
      res.push_back(cache);
    }

    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  TreeNode *root1 = new TreeNode(3);
  root1->left = new TreeNode(9);
  root1->left->left = new TreeNode(9);
  root1->left->left->left = new TreeNode(9);
  root1->right = new TreeNode(20);
  root1->right->right = new TreeNode(7);
  root1->right->right->right = new TreeNode(7);

  Solution solve;
  auto result = solve.levelOrderBottom(root1);

  return 0;
}
