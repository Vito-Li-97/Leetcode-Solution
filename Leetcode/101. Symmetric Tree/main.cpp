
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

class Solution {  // 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 public:
  // 方法一：递归
  // O(n); O(n);
  bool recursion(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
      return true;
    }
    if (p == nullptr || q == nullptr) {
      return false;
    }
    if (p->val != q->val) {
      return false;
    }
    return recursion(p->left, q->right) && recursion(p->right, q->left);
  }
  bool isSymmetric(TreeNode *root) {
    return recursion(root->left, root->right);
  }

  // 方法二：迭代
  // O(n); O(n);
  // 首先引入一个队列。初始化时把根节点入队两次。
  // 每次提取两个结点并比较它们的值（队列中每两个连续的结点应该是相等的，而且它们的子树互为镜像），
  // 然后将两个结点的左右子结点按相反的顺序插入队列中。
  // 当队列为空时，或者检测到树不对称（即从队列中取出两个不相等的连续结点）时，算法结束。
  bool check(TreeNode *p, TreeNode *q) {
    queue<TreeNode *> queue1;
    queue1.push(p);
    queue1.push(q);

    while (!queue1.empty()) {  // 如果queue空了，跳出
      TreeNode *p = queue1.front();
      queue1.pop();
      TreeNode *q = queue1.front();
      queue1.pop();
      if (p == nullptr && q == nullptr) {
        continue;
      }
      if (p == nullptr || q == nullptr) {
        return false;
      }
      if (p->val != q->val) {
        return false;
      }

      // 将对应的子节点入栈（镜像所以是交叉入栈）
      queue1.push(p->left);
      queue1.push(q->right);
      queue1.push(p->right);
      queue1.push(q->left);
    }

    return queue1.empty();
  }

  bool isSymmetric_2(TreeNode *root) {
    return check(root, root);
  }
};

int main() {
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(2);
  root1->left->left = new TreeNode(3);
  root1->left->right = new TreeNode(4);
  root1->right->left = new TreeNode(4);
  root1->right->right = new TreeNode(3);

  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->right = new TreeNode(2);
  root2->left->right = new TreeNode(3);
  root2->right->right = new TreeNode(3);

  Solution solve;
  bool result1 = solve.isSymmetric_2(root1);
  cout << result1 << endl;
  bool result2 = solve.isSymmetric_2(root2);
  cout << result2 << endl;

  return 0;
}
