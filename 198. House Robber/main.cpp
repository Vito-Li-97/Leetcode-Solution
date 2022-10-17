
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {  // 打家劫舍
    int n = nums.size();
    vector<int> dp(2, 0);  // 边界条件 n=0,1,2
    if (n == 0) {
      return 0;
    }
    dp[0] = nums[0];
    if (n == 1) {
      return dp[0];
    }
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++) {
      int temp = dp[1];
      dp[1] = max(dp[0] + nums[i], dp[1]);  // 针对 nums[i] 使用或不使用两种情况分类
                                            // 写出 dp[i] 分别和 dp[i-2] 与 dp[i-1] 的关系
      dp[0] = temp;
    }
    return dp[1];
  }
};

int main() {
  vector<int> nums = {0};
  Solution solve;
  cout << solve.rob(nums) << endl;

  return 0;
}
