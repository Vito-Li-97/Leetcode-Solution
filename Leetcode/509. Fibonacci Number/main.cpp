
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int fib(int n) {  // dp
    if (n <= 1) {
      return n;
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }

  int fib_1(int n) {  // dp improved
    if (n <= 1) {
      return n;
    }
    int cache1 = 0, cache2 = 1, cache3;
    for (int i = 2; i < n + 1; i++) {
      cache3 = cache1 + cache2;
      cache1 = cache2;
      cache2 = cache3;
    }
    return cache3;
  }

  int fib_2(int n) {  // recursion
    if (n <= 1) {
      return n;
    }
    return fib_2(n - 1) + fib_2(n - 2);
  }
};

int main() {
  vector<int> test = {4, 5, 6, 10, 20};

  Solution solve;
  for (int i = 0; i < test.size(); i++) {
    cout << solve.fib_1(test[i]) << endl;
  }

  return 0;
}