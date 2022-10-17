#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {  // 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 public:
  vector<vector<int>> result;          // 存放符合条件结果的集合
  vector<int> path;                    // 用来存放符合条件结果
  void dfs(int n, int k, int index) {  // index 记录本层递归中，集合的遍历位置。
    if (path.size() == k) {            // 如果 path 已取了 k 个数，则计入result并return
      result.push_back(path);
      return;
    }
    for (int i = index; i <= n - (k - path.size()) + 1; i++) {
      // 横向遍历，从 index 开始到 n - (k - path.size()) + 1 (剪枝)
      path.push_back(i);  // 处理节点
      dfs(n, k, i + 1);   // 递归，控制树的纵向遍历，下一层搜索从i+1开始
      path.pop_back();    // return就回溯，撤销处理的节点
    }
  }
  vector<vector<int>> combine(int n, int k) {
    dfs(n, k, 1);
    return result;
  }

  //-------------------------------------------------------------------------------

  void dfs_1(int cur, int n, int k) {
    // 剪枝：path 长度加上区间 [cur, n] 的长度小于 k，不可能构造出长度为 k 的 path
    if (path.size() + (n - cur + 1) < k) {
      return;
    }
    if (path.size() == k) {  // 记录合法的答案
      result.push_back(path);
      return;
    }
    path.push_back(cur);  // 考虑选择当前位置
    dfs_1(cur + 1, n, k);
    path.pop_back();
    dfs_1(cur + 1, n, k);  // 考虑不选择当前位置
  }
  vector<vector<int>> combine_1(int n, int k) {
    dfs_1(1, n, k);
    return result;
  }

  //------------------------------------------------------------------------------
};

int main() {
  Solution solve;
  vector<vector<int>> result = solve.combine_1(4, 2);
  cout << result.size() << endl;

  return 0;
}

/*
void backtracking(参数) { // 回溯递归的模板
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}
*/