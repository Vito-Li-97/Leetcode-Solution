
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int uniquePaths(int m, int n) {                  // dp
    vector<vector<int>> dp(m, vector<int>(n, 0));  // [0 ~ m-1][0 ~ n-1]
    for (int i = 0; i < m; i++) {
      dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
      dp[0][i] = 1;
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
      }
    }
    return dp[m - 1][n - 1];
  }

  int uniquePaths_1(int m, int n) {  // Combinatorial
    if (m < n) {
      swap(m, n);
    }
    long long result = 1;
    for (int i = m, j = 1; j < n; i++, j++) {
      result = result * i / j;
    }
    return result;
  }

  int uniquePaths_2(int m, int n) {  // 滚动数组，空间复杂度 O(n)
    int cur[n];
    for (int i = 0; i < n; i++) {
      cur[i] = 1;
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        cur[j] += cur[j - 1];  // 每行里每个元素，自己等于自己加上左边的，从左到右
      }
    }
    return cur[n - 1];
  }
};

int main() {
  int m = 3, n = 7;
  Solution solve;
  cout << solve.uniquePaths_2(m, n) << endl;

  return 0;
}