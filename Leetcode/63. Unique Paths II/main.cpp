
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {  // 当 obstacleGrid[][]=1 就退出循环
      dp[i][0] = 1;                                           // 后面的 dp 都为0
    }
    for (int i = 0; i < n && obstacleGrid[0][i] == 0; i++) {
      dp[0][i] = 1;
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (obstacleGrid[i][j] == 0) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }
    }
    return dp[m - 1][n - 1];
  }

  int uniquePathsWithObstacles_1(vector<vector<int>>& obstacleGrid) {  // save memory
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<int> dp(n + 1, 0);  // dp的1~n对应obstacleGrid的0~n-1

    dp[1] = 1 - obstacleGrid[0][0];
    for (int i = 0; i < m; i++) {
      for (int j = 1; j < n + 1; j++) {
        if (obstacleGrid[i][j - 1] == 0) {
          dp[j] += dp[j - 1];
        } else {
          dp[j] = 0;
        }
      }
    }
    return dp[n];
  }
};

int main() {
  vector<vector<vector<int>>> obstacleGrid = {
      {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}},
      {{1, 0}},
      {{0, 1}},
      {{0}, {1}}};

  Solution solve;
  cout << solve.uniquePathsWithObstacles_1(obstacleGrid[0]) << endl;
  cout << solve.uniquePathsWithObstacles_1(obstacleGrid[3]) << endl;

  return 0;
}