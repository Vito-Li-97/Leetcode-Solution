
#include <iostream>
#include <vector>
using namespace std;

// 有n件物品和一个最多能背重量为w 的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。
// 每件物品只能用一次，求解将装入背包里物品价值总和最大为多少。

class Solution {
 public:
  int knapsack(vector<int> weight, vector<int> value, int bagWeight) {
    int n = weight.size();

    vector<vector<int>> dp(n, vector<int>(bagWeight + 1, 0));
    // dp[i][j] 代表在 0~i 号元素里取 weight sum 不大于 j 的元素，其 value sum 的最大值

    for (int i = weight[0]; i <= bagWeight; i++) {
      dp[0][i] = value[0];
    }

    for (int i = 1; i < n; i++) {                // 遍历元素范围
      for (int j = 1; j < bagWeight + 1; j++) {  // 遍历 weight 限制
        if (j >= weight[i]) {                    // 放入元素i的条件是 j >= weight[i]
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
      }
    }

    return dp[n - 1][bagWeight];
  };
};

int main() {
  int bagWeight = 4;
  vector<int> weight = {1, 3, 4};
  vector<int> value = {15, 20, 30};

  Solution solve;
  int result = solve.knapsack(weight, value, bagWeight);
  cout << result << endl;

  return 0;
}