
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int lastStoneWeightII(vector<int>& stones) {
    // 最后一块石头的重量等于，各块石头加或减组合在一起的结果
    int sum = 0;
    for (auto& elem : stones) {
      sum += elem;
    }
    int target = sum / 2;  // 取一部分元素的重量和，使其最接近 target

    int n = stones.size();
    vector<int> dp(target + 1, 0);  // i轮的 dp[j] 表示在0~i号元素中，重量和小于等于j时能取的最大重量和

    for (int i = 1; i < target + 1; i++) {
      if (i >= stones[0]) {
        dp[i] = stones[0];
      }
    }

    for (int i = 1; i < n; i++) {
      for (int j = target; j > 0; j--) {
        if (j >= stones[i]) {
          dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        }
      }
    }

    return sum - 2 * dp[target];
  }
};

int main() {
  vector<int> v1 = {2, 7, 4, 1, 8, 1};

  Solution solve;
  cout << solve.lastStoneWeightII(v1) << endl;

  return 0;
}