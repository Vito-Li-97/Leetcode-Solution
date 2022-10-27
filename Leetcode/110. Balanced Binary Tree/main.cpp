
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

class Solution {  // 给定一个二叉树，判断它是否是高度平衡的二叉树。
 public:
  // 方法一：从上到底
  // 平均 O(nlogn) 最坏 O(n^2) ;
  // 最差情况下，isBalanced() 遍历树所有节点，占用 O(n) ；
  // height() 需要遍历各子树的所有节点，子树的节点数的平均复杂度为 O(logn)，最坏链状 O(n)
  // O(n); 空间复杂度主要取决于递归调用的层数
  // 每调用一次 isBalanced 就要调用2次 height
  int height(TreeNode *root) {  // 计算该节点的最大高度
    if (root == nullptr) {
      return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
  }

  bool isBalanced(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }

    return abs(height(root->left) - height(root->right)) <= 1 &&
           isBalanced(root->left) &&
           isBalanced(root->right);  //左右子节点子树均为平衡二叉树，且，整个节点树也为平衡二叉树
  }

  // 方法二：从底到上
  // O(n);
  // O(n);
  // 后序遍历，对于当前遍历到的节点，先递归地判断其左右子树是否平衡，再判断以当前节点为根的子树是否平衡。
  // 如果一棵子树是平衡的，则返回其高度（高度一定是非负整数），否则返回 −1。
  int height_2(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    int a = height_2(root->left);
    int b = height_2(root->right);
    if (a < 0 || b < 0) {
      return -1;
    }
    if (abs(a - b) > 1) {
      return -1;
    }
    return max(a, b) + 1;
  }

  bool isBalanced_2(TreeNode *root) {
    return height_2(root) >= 0;
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
  bool result1 = solve.isBalanced(root1);
  cout << result1 << endl;
  bool result2 = solve.isBalanced_2(root1);
  cout << result2 << endl;

  return 0;
}
