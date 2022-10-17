
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {  //给你一个 只包含正整数 的 非空 数组 nums 。
                  //请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 public:
  bool canPartition(vector<int>& nums) {  // 01 bag
    int n = nums.size();
    int target = 0;
    for (int i = 0; i < nums.size(); i++) {
      target += nums[i];
    }
    if (target & 1) {
      return false;
    }
    target /= 2;
    if (*max_element(nums.begin(), nums.end()) > target) {
      return false;
    }

    // dp[i][j] 表示从下标为[0-i]的元素里取总和不大于j的元素，总和最大是多少。
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    for (int i = nums[0]; i < target + 1; i++) {
      dp[0][i] = nums[0];
    }

    for (int i = 1; i < n; i++) {
      for (int j = 1; j < target + 1; j++) {
        if (j >= nums[i]) {  // 如果 j 放得下元素i
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
          // 如果放入元素i：dp[i-1][j]
          // 如果不放元素i：dp[i-1][j-nums[i]]+nums[i]
        } else {  // 如果 j 放不下元素i
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[n - 1][target] == target;
  }

  bool canPartition_1(vector<int>& nums) {  // 1D vector
    int n = nums.size();
    int target = 0;
    for (int i = 0; i < nums.size(); i++) {
      target += nums[i];
    }
    if (target & 1) {
      return false;
    }
    target /= 2;
    if (*max_element(nums.begin(), nums.end()) > target) {
      return false;
    }

    // dp[i] 表示取元素和能否满足等于i
    vector<int> dp(target + 1, 0);
    // 初始条件：从0号元素里选，只能填满 j = 0 或 nums[0]
    dp[0] = 1;
    dp[nums[0]] = 1;

    for (int i = 1; i < n; i++) {
      for (int j = target; j > 0; j--) {  // 数组从右往左遍历，因为更新用到左边的旧数据
        if (j >= nums[i]) {               // 如果能包含元素 i
          dp[j] = dp[j] | dp[j - nums[i]];
          // 如果不含元素 i：dp[i][j] = dp[i-1][j]
          // 如果包含元素 i：dp[i][j] = dp[i-1][j-nums[i]]
        }
      }
    }

    return dp[target];
  }
};

int main() {
  vector<int> inputs = {2, 2, 3, 5};
  Solution solve;
  cout << solve.canPartition(inputs) << endl
       << solve.canPartition_1(inputs) << endl;

  return 0;
}