#include <iostream>
#include <vector>
using namespace std;

class Solution {  // 有 n 个气球，每个气球上都标有一个数字，这些数字存在数组 nums 中。
 public:
  void backtrack(vector<int> val, int n_coins, int& max_n_coins) {
    if (val.size() == 2) {
      return;
    }
    for (int i = 1; i <= val.size() - 2; i++) {
      int tmp = val[i];
      n_coins += val[i - 1] * val[i] * val[i + 1];  // 处理节点
      val.erase(val.begin() + i);
      if (max_n_coins < n_coins) {
        max_n_coins = n_coins;
      }

      backtrack(val, n_coins, max_n_coins);  // 递归

      val.insert(val.begin() + i, tmp);
      n_coins -= val[i - 1] * val[i] * val[i + 1];  // 回溯
    }
  }
  int maxCoins(vector<int>& nums) {  // 递归回溯
    int n = nums.size();
    if (n == 0) {
      return 0;
    }
    vector<int> val(nums.begin(), nums.end());
    val.insert(val.begin(), 1);
    val.push_back(1);

    int max_n_coins = 0;
    backtrack(val, 0, max_n_coins);
    return max_n_coins;
  }

  int maxCoins_1(vector<int>& nums) {  // dp
    int n = nums.size();
    if (n == 0) {
      return 0;
    }

    vector<int> val(nums.begin(), nums.end());
    val.insert(val.begin(), 1);
    val.push_back(1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    // 将整个过程逆向，看成是一个个气球接连浮起的过程，每次浮起都获得 coin
    // dp[i][j] 代表将[i,j]区间填满气球所得到的的最大coin数
    // i>j时，dp[i][j] = 0;
    // dp[i][i] = val[i - 1] * val[i] * val[i + 1]

    for (int i = n; i >= 1; i--) {  // [0 [1 n] n+1]
      for (int j = i; j <= n; j++) {
        for (int k = i; k <= j; k++) {
          // 在区间[i,j]中，第一个浮起的气球为 num[k]
          // k没浮起来时，dp[i,j] 被分为 dp[i,k-1] 和 dp[k+1][j] 以及将浮起的 k
          dp[i][j] = max(dp[i][k - 1] + dp[k + 1][j] + val[i - 1] * val[k] * val[j + 1],
                         dp[i][j]);
        }
      }
    }

    return dp[1][n];
  }
};

int main() {
  vector<int> test = {3, 1, 5, 8};

  Solution solve;
  cout << solve.maxCoins(test) << endl
       << solve.maxCoins_1(test) << endl;

  return 0;
}