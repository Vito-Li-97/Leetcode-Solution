
#include <iostream>
#include <stack>
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

class Solution {  // 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
 public:
  // 方法一：递归
  // O(n);
  // O(n);
  void postorder(TreeNode *root, vector<int> &res) {
    if (root == nullptr) {
      return;
    }
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
  }

  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    postorder(root, res);
    return res;
  }

  // 方法二：迭代
  // O(n);
  // O(n);
  // 每遍历一个节点，先遍历左节点，直到没有左节点，然后再遍历右节点，
  // 对每个遍历的节点重复该步骤，遍历完左子树，再遍历完右子树，最后处理本节点

  // 后序遍历中，从栈中弹出的节点，我们只能确定其左子树肯定访问完了，但是无法确定右子树是否访问过。
  // 当访问完一棵子树的时候，我们用prev指向该节点。
  // 在回溯到父节点的时候，我们可以依据prev是指向左子节点，还是右子节点，来判断父节点的访问情况。
  vector<int> postorderTraversal_2(TreeNode *root) {
    vector<int> res;
    if (root == nullptr) {
      return res;
    }
    stack<TreeNode *> st;
    TreeNode *prev = nullptr;  // 记录上一个已被遍历的节点

    while (root != nullptr || st.size() != 0) {  // 当前访问的节点root为空，且栈（待处理的节点）为空，才跳出循环
      while (root != nullptr) {                  // 若root不为空，则root入栈，访问左节点
        st.push(root);
        root = root->left;
      }
      root = st.top();
      st.pop();
      if (root->right == nullptr || root->right == prev) {
        // 若root的右节点为空，或右节点已被遍历，
        // 说明root的右子树不需要再遍历访问，则仅处理root
        res.push_back(root->val);
        prev = root;     // prev记录最新已被处理的节点
        root = nullptr;  // 当前访问的节点root已被处理，将root置空
      } else {
        // 若root的右节点不为空，且右节点也不等于prev（即右节点未被遍历）
        // 说明需要遍历root的右子树
        // 则root入栈，访问root右节点
        st.push(root);
        root = root->right;
      }
    }
    return res;
  }
};

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = nullptr;
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);

  Solution solve;
  vector<int> result = solve.postorderTraversal(root);
  vector<int> result2 = solve.postorderTraversal_2(root);
  for (const auto &elem : result) {
    cout << elem << " ";
  }
  for (const auto &elem : result2) {
    cout << elem << " ";
  }

  return 0;
}