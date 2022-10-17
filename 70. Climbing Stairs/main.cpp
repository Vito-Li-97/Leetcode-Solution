
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int climbStairs(int n) {  // dp
    int dp[3] = {0};
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 1; i < n + 1; i++) {  // n 次
      dp[2] = dp[0] + dp[1];
      dp[0] = dp[1];
      dp[1] = dp[2];
    }
    return dp[2];
  }

  int climbStairs_1(int n) {  // 通项公式
    double sqrt5 = sqrt(5.0);
    double result = (pow(sqrt5 + 1, n + 1) - pow(-sqrt5 + 1, n + 1)) / (pow(2, n + 1) * sqrt5);
    return (int)round(result);
  }

  vector<vector<long long>> multiply(vector<vector<long long>> &a, vector<vector<long long>> &b) {
    vector<vector<long long>> c(2, vector<long long>(2));
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
      }
    }
    return c;
  }

  vector<vector<long long>> matrixPow(vector<vector<long long>> a, int n) {
    vector<vector<long long>> ret = {{1, 0}, {0, 1}};
    while (n > 0) {
      if ((n & 1) == 1) {
        ret = multiply(ret, a);
      }
      n >>= 1;
      a = multiply(a, a);
    }
    return ret;
  }

  int climbStairs_2(int n) {  // 矩阵快速幂
    vector<vector<long long>> ret = {{1, 1}, {1, 0}};
    vector<vector<long long>> res = matrixPow(ret, n);
    return res[0][0];
  }
};

int main() {
  int n = 9;

  Solution solve;
  cout << solve.climbStairs(n) << endl
       << solve.climbStairs_1(n) << endl
       << solve.climbStairs_2(n) << endl;

  return 0;
}