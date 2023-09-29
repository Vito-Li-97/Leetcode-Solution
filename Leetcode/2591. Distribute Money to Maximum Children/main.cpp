
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    unordered_map<int, bool> isRoot;      // 数值对应的节点是否为根节点的哈希表
    unordered_map<int, TreeNode*> nodes;  // 数值与对应节点的哈希表
    for (const auto& d : descriptions) {
      int p = d[0];
      int c = d[1];
      bool left = d[2];
      if (!isRoot.count(p)) {
        isRoot[p] = true;
      }
      isRoot[c] = false;
      // 创建或更新节点
      if (!nodes.count(p)) {
        nodes[p] = new TreeNode(p);
      }
      if (!nodes.count(c)) {
        nodes[c] = new TreeNode(c);
      }
      if (left) {
        nodes[p]->left = nodes[c];
      } else {
        nodes[p]->right = nodes[c];
      }
    }
    // 寻找根节点
    int root = -1;
    for (const auto& [val, r] : isRoot) {
      if (r) {
        root = val;
        break;
      }
    }
    return nodes[root];
  }
};