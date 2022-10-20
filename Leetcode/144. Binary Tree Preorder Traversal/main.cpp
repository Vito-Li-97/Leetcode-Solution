
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