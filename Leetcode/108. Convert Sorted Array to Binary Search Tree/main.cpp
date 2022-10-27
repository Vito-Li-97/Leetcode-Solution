
#include <iostream>
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

class Solution {  // 给你一个整数数组 nums ，其中元素已经按升序排列，请你将其转换为一棵高度平衡二叉搜索树。
 public:
  // 方法一：中序遍历，选择中间位置左边或右边的数字作为根节点
  // O(n); n = nums.size(), 每个数字只访问一次。
  // O(n); 递归栈大小为二叉树的高度，2^(k-1) < n <= 2^k-1; S = k; S = log(n)
  TreeNode *recursion(vector<int> &nums, int left, int right) {
    if (left > right) {
      return nullptr;
    }

    int mid = (left + right + rand() % 2) / 2;  // +0 or +1
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = recursion(nums, left, mid - 1);
    root->right = recursion(nums, mid + 1, right);
    return root;
  }

  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return recursion(nums, 0, nums.size() - 1);
  }
};

int main() {
  vector<int> test = {-10, -3, 0, 5, 9};

  Solution solve;
  TreeNode *result1 = solve.sortedArrayToBST(test);

  return 0;
}
