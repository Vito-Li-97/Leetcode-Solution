#include <algorithm>
#include <iostream>
#include <stack>
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

class Solution {  // 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
 public:
  // 方法一：递归
  // O(n); O(n); 节点数n
  void travIn_R(TreeNode *root, vector<int> &result) {
    if (!root) {
      return;
    }
    travIn_R(root->left, result);
    result.push_back(root->val);
    travIn_R(root->right, result);
  }

  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    travIn_R(root, result);
    return result;
  }

  // 方法二：迭代
  // O(n); 最坏O(n); 节点数n
  // 每到一个节点 A，因为根的访问在中间，将 A 入栈。然后遍历左子树，接着访问 A，最后遍历右子树。
  // 在访问完 A 后，A 就可以出栈了。因为 A 和其左子树都已经访问完成。
  vector<int> inorderTraversal_2(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> stack_use;  // 记录，待处理的节点
    while (root != nullptr || stack_use.size()) {
      // root为空 且 stack为空 代表所有节点全部处理完了，跳出
      while (root != nullptr) {
        // 如果root非空，root入栈，让root等于其左节点，直到root为空
        // root为空时，跳出
        stack_use.push(root);
        root = root->left;
      }
      root = stack_use.top();  // 回到父节点
      result.push_back(root->val);
      stack_use.pop();
      root = root->right;  // 开始遍历root的右节点
    }
    return result;
  }

  // 方法三：Morris 中序遍历
  // O(n); O(1)
  vector<int> inorderTraversal_3(TreeNode *root) {
    vector<int> result;
    TreeNode *cur = root;

    while (cur != nullptr) {       // 当 cur 为空，说明所有节点都遍历完，跳出
      if (cur->left == nullptr) {  // 如果无左孩，将cur的值加入答案，再cur = cur->right
        result.push_back(cur->val);
        cur = cur->right;
      } else {                      // 如果有左孩，则找到 cur 左子树上最右的节点
                                    //（即左子树中序遍历的最后一个节点，x在中序遍历中的前驱节点），记为 pre
        TreeNode *pre = cur->left;  // pre 是当前节点向左走一步，然后一直向右走至尽头
        while (pre->right != nullptr && pre->right != cur) {
          pre = pre->right;
        }

        if (pre->right == nullptr) {  // 如果pre无右孩，pre->right = cur; cur = cur->left
          pre->right = cur;
          cur = cur->left;
        } else {  // 如果pre有右孩，则说明有pre->right = cur; 已经遍历完x的左子树，
                  // 取 pre->right = nullptr，将 cur 值加入答案，然后 cur = cur->right
          pre->right = nullptr;
          result.push_back(cur->val);
          cur = cur->right;
        }
      }
    }

    return result;
  }
};

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = nullptr;
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);

  Solution solve;
  vector<int> result = solve.inorderTraversal_3(root);
  for (const auto &elem : result) {
    cout << elem << " ";
  }

  return 0;
}
