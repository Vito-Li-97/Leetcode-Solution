
#include <deque>
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

// 给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。
// 即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行。
class Solution {
 public:
  // 方法一：BFS 双端队列
  // O(n);
  // O(n);
  // 广度优先搜索遍历仍然从左往右按顺序拓展，
  // 但是对当节点的存储，我们选择是从左至右还是从右至左的：
  // 如果从左至右，将被遍历到的元素插入至双端队列的末尾。
  // 如果从右至左，将被遍历到的元素插入至双端队列的头部。
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr) {
      return res;
    }
    queue<TreeNode *> qt;  // 单向队列储存需要遍历的节点
    qt.push(root);
    bool isOrderLeft = true;  // 是否从左到右读取节点val

    while (!qt.empty()) {
      int qts = qt.size();
      deque<int> dqv;  // 双端队列储存遍历得到的节点值
      for (int i = 0; i < qts; i++) {
        TreeNode *cur = qt.front();
        qt.pop();
        if (isOrderLeft) {
          // qt 读取节点的顺序始终是从左到右，左元素先读右元素后读
          // dqv的 begin（front） 和 end（back） 与数组 cache 一致
          // dqv 新入back，先入的左元素在begin处（节点值从左到右遍历）；新入front，先入的左元素在end处（节点值从右到左遍历）
          dqv.push_back(cur->val);
        } else {
          dqv.push_front(cur->val);
        }

        if (cur->left != nullptr) {
          qt.push(cur->left);
        }
        if (cur->right != nullptr) {
          qt.push(cur->right);
        }
      }

      vector<int> cache(dqv.begin(), dqv.end());
      res.push_back(cache);
      isOrderLeft = !isOrderLeft;
    }

    return res;
  }

  // 方法二： 双端对列调换插入方向和读取方向，真正的锯齿顺序遍历节点
  // O(n);
  // O(n);
  vector<vector<int>> zigzagLevelOrder_2(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr) {
      return res;
    }
    deque<TreeNode *> dqt;  // 储存需要遍历的节点，
    // 节点出顺序和子节点进顺序相同
    // 子节点出顺序与子节点进顺序相反
    dqt.push_back(root);
    bool isOrderLeft = true;

    while (!dqt.empty()) {
      int dqts = dqt.size();
      vector<int> cache;
      for (int i = 0; i < dqts; i++) {
        // 将先读的节点的子节点存在队列尾
        TreeNode *cur;
        if (isOrderLeft) {
          cur = dqt.front();
          dqt.pop_front();
          // 节点先出front
          // 子节点进back
          if (cur->left != nullptr) {
            dqt.push_back(cur->left);
          }
          if (cur->right != nullptr) {
            dqt.push_back(cur->right);
          }
        } else {
          cur = dqt.back();
          dqt.pop_back();
          if (cur->right != nullptr) {
            dqt.push_front(cur->right);
          }
          if (cur->left != nullptr) {
            dqt.push_front(cur->left);
          }
        }
        cache.push_back(cur->val);
      }
      res.push_back(cache);
      isOrderLeft = !isOrderLeft;
    }

    return res;
  }

  // 方法三： 数组索引
  // O(n);
  // O(n);
};

int main() {
  TreeNode *root1 = new TreeNode(3);
  root1->left = new TreeNode(9);
  root1->left->left = new TreeNode(10);
  root1->left->left->left = new TreeNode(11);
  root1->right = new TreeNode(20);
  root1->right->right = new TreeNode(7);
  root1->right->right->right = new TreeNode(10);

  Solution solve;
  auto result = solve.zigzagLevelOrder(root1);
  auto result2 = solve.zigzagLevelOrder_2(root1);

  return 0;
}
