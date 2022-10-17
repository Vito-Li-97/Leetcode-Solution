
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n + 1, 0);  // 到达i台阶时已支付的体力

    if (n == 2) {
      return min(cost[0], cost[1]);
    }

    for (int i = 2; i < n + 1; i++) {
      dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }

    return dp[n];
  }
};

int main() {
  vector<int> test = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

  Solution n1;
  int ans = n1.minCostClimbingStairs(test);
  cout << ans << endl;

  return 1;
}