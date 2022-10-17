
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 private:
  vector<vector<int>> result;
  vector<int> path;
  void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
    if (sum == target) {
      result.push_back(path);
      return;
    }

    // 如果 sum + candidates[i] > target 就终止遍历
    for (int i = startIndex; sum + candidates[i] <= target && i < candidates.size(); i++) {
      sum += candidates[i];
      path.push_back(candidates[i]);
      backtracking(candidates, target, sum, i);
      sum -= candidates[i];
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    result.clear();
    path.clear();
    sort(candidates.begin(), candidates.end());  // 需要排序
    backtracking(candidates, target, 0, 0);
    return result;
  }
};

int main() {
  vector<int> candidates{2, 3, 7, 6};
  int target = 7;

  Solution solve;
  vector<vector<int>> ans = solve.combinationSum(candidates, target);

  return 0;
}