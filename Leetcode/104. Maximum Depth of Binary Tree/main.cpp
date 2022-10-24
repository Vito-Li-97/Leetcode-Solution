
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

class Solution {  // 给定一个二叉树，找出其最大深度。
 public:
  // 方法一：深度优先搜索
  // O(n); O(height);
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }

  // 方法二：广度优先搜索
  // O(n); 最坏O(n);
  // 我们广度优先搜索的队列里存放的是「当前层的所有节点」。
  // 每次拓展下一层的时候，我们需要将队列里的所有节点都拿出来进行拓展，
  // 这样能保证每次拓展完的时候队列里存放的是当前层的所有节点，即一层一层地进行拓展
  int maxDepth_2(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int res = 0;
    queue<TreeNode *> q;
    q.push(root);

    while (q.size() != 0) {
      int qs = q.size();
      for (int i = 0; i < qs; i++) {
        root = q.front();
        if (root->left != nullptr) {
          q.push(root->left);
        }
        if (root->right != nullptr) {
          q.push(root->right);
        }
        q.pop();
      }
      res++;
    }

    return res;
  }
};

int main() {
  TreeNode *root1 = new TreeNode(3);
  root1->left = new TreeNode(9);
  root1->right = new TreeNode(20);
  root1->right->left = new TreeNode(15);
  root1->right->right = new TreeNode(7);

  Solution solve;
  int result1 = solve.maxDepth(root1);
  cout << result1 << endl;
  int result2 = solve.maxDepth_2(root1);
  cout << result2 << endl;

  return 0;
}
