
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

class Solution {  // 判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和 targetSum
 public:
  // 方法一：DFS
  // O(n);
  // O(height);
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return false;
    }
    if (root->left == nullptr && root->right == nullptr) {  // 左右节点皆空时中止递归
      return targetSum == root->val;
    }

    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);  // 有左右节点时继续递归
  }

  // 方法二：BFS
  // O(n);
  // O(n);
  // 这样我们使用两个队列，分别存储将要遍历的节点，以及根节点到这些节点的路径和即可
  bool hasPathSum_2(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return false;
    }
    queue<TreeNode *> q1;
    queue<int> q2;
    q1.push(root);
    q2.push(root->val);

    while (q1.size() != 0) {
      TreeNode *cur = q1.front();
      int temp = q2.front();
      q1.pop();
      q2.pop();

      if (cur->left == nullptr && cur->right == nullptr) {
        if (temp == targetSum) {
          return true;
        }
        continue;
      }

      if (cur->left != nullptr) {
        q1.push(cur->left);
        q2.push(cur->left->val + temp);  // 对于每个节点，记录从根节点到该节点的 val 累加和
      }
      if (cur->right != nullptr) {
        q1.push(cur->right);
        q2.push(cur->right->val + temp);
      }
    }

    return false;
  }
};

int main() {
  TreeNode *root1 = new TreeNode(3);
  root1->left = new TreeNode(9);
  root1->right = new TreeNode(20);
  root1->right->left = new TreeNode(15);
  root1->right->right = new TreeNode(7);

  int target = 12;

  Solution solve;
  int result1 = solve.hasPathSum(root1, target);
  cout << result1 << endl;
  int result2 = solve.hasPathSum_2(root1, target);
  cout << result2 << endl;

  return 0;
}
