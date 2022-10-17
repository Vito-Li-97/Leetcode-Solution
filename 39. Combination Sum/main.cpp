
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> result;
  vector<int> temp;
  int sum = 0;

  void dfs(vector<int>& candidates, int target, int index) {
    if (sum > target) {
      return;
    } else if (sum == target) {
      result.push_back(temp);
      return;
    }

    for (int i = index; i < candidates.size() && sum + candidates[i] <= target; i++) {  // 剪枝
      temp.push_back(candidates[i]);
      sum += candidates[i];
      dfs(candidates, target, i);  // 节点处横向遍历
      temp.pop_back();
      sum -= candidates[i];
    }
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    result.clear();
    temp.clear();
    sum = 0;
    sort(candidates.begin(), candidates.end());

    dfs(candidates, target, 0);
    return result;
  }

  //----------------------------------------------------------------------------------------
  void dfs_1(vector<int>& candidates, int target, int index) {  // 测试用例
    if (sum > target) {
      return;
    } else if (sum == target) {
      result.push_back(temp);
      return;
    }

    for (int i = index; i < candidates.size(); i++) {  // 剪枝
      if (sum + candidates[i] > target) {
        break;
      }
      temp.push_back(candidates[i]);  // 从n前往n+1节点
      sum += candidates[i];

      cout << "i = " << i << " temp = ";
      for (auto& elem : temp) {
        cout << elem << " ";
      }
      cout << endl;

      dfs_1(candidates, target, i);  // 在 n+1 节点处横向遍历
      temp.pop_back();               // 回溯，指向上一节点 n
      sum -= candidates[i];
    }
    return;
  }
};

int main() {
  vector<int> candidates{2, 3, 7, 6};
  int target = 7;

  Solution solve;
  vector<vector<int>> ans = solve.combinationSum(candidates, target);

  return 0;
}