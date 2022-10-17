#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int integerBreak(int n) {
    vector<int> dp(n + 1, 0);  // dp[i] 为 将数i拆分后的最大乘积

    dp[2] = 1;  // 把2拆分后的最大积为1

    for (int i = 3; i < n + 1; i++) {
      for (int j = 1; j < i; j++) {                           // 将i分为2或更多数
        dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));  // 对 i-j 不拆分或是分为2或更多数
      }
    }

    return dp[n];
  }
};

int main() {
  cout << 7 << endl;
  return 0;
}
