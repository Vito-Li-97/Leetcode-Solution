
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

class Solution {  // 给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
 public:
  // 方法一：深度优先搜索
  // O(min(m,n)); O(min(m,n));
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
      return true;
    }
    if (p == nullptr || q == nullptr) {
      return false;
    }
    if (p->val != q->val) {
      return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }

  // 方法二：广度优先搜索
  // O(min(m,n)); O(min(m,n));
  // 使用两个队列分别存储两个二叉树的节点。初始时将两个二叉树的根节点分别加入两个队列。
  // 每次从两个队列各取出一个节点，进行如下比较操作。
  // 如果两个节点的子节点的结构相同，则将两个节点的非空子节点分别加入两个队列，
  // 子节点加入队列时需要注意顺序，如果左右子节点都不为空，则先加入左子节点，后加入右子节点。
  bool isSameTree_1(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
      return true;
    }
    if (p == nullptr || q == nullptr) {
      return false;
    }

    // 若p q均不为空，将二者入栈
    queue<TreeNode *> queue1, queue2;
    queue1.push(p);
    queue2.push(q);

    while (!queue1.empty() && !queue2.empty()) {  // 如果有queue空了，跳出
      TreeNode *node1 = queue1.front();
      TreeNode *node2 = queue2.front();
      if (node1->val != node2->val) {
        return false;
      }
      queue1.pop();
      queue2.pop();

      TreeNode *left1 = node1->left,
               *left2 = node2->left,
               *right1 = node1->right,
               *right2 = node2->right;
      // 检验左右子节点的结构是否一致
      if ((left1 == nullptr) ^ (left2 == nullptr)) {
        return false;
      }
      if ((right1 == nullptr) ^ (right2 == nullptr)) {
        return false;
      }

      // 将非空的左右子节点入栈
      if (left1 != nullptr) {
        queue1.push(left1);
      }
      if (left2 != nullptr) {
        queue2.push(left2);
      }
      if (right1 != nullptr) {
        queue1.push(right1);
      }
      if (right2 != nullptr) {
        queue2.push(right2);
      }
    }

    return queue1.empty() && queue2.empty();
  }
};

int main() {
  TreeNode *root1 = new TreeNode(1);
  root1->left = nullptr;
  root1->right = new TreeNode(2);
  root1->right->left = new TreeNode(3);

  TreeNode *root2 = new TreeNode(1);
  root2->left = nullptr;
  root2->right = new TreeNode(3);
  root2->right->left = new TreeNode(2);

  Solution solve;
  bool result = solve.isSameTree_1(root1, root2);
  cout << result << endl;

  return 0;
}
