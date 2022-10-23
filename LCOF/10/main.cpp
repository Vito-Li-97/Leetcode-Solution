
#include <iostream>
#include <vector>
using namespace std;

class Solution {  // 写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）
 public:
  // 方法一：动态规划
  // O(n) O(1)
  int fib(int n) {
    int f0 = 0;
    int f1 = 1;
    int f2;
    f2 = n == 1 ? f1 : f0;

    for (int i = 2; i <= n; i++) {
      f2 = (f0 + f1) % 1000000007;  // 取模防止超出int界限
      f0 = f1;
      f1 = f2;
    }

    return f2;
  }

  //方法二：矩阵快速幂
  // O(logn) O(1)
  const long MOD = 1000000007;

  vector<vector<long long>> multiply_matrix(vector<vector<long long>> a, vector<vector<long long>> b) {
    vector<vector<long long>> result{{0, 0}, {0, 0}};
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        result[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % MOD;
      }
    }
    return result;
  }

  vector<vector<long long>> pow_matrix(vector<vector<long long>> M, int n) {
    vector<vector<long long>> result = {{1, 0}, {0, 1}};
    while (n > 0) {
      if (n & 1) {  // 若n的二进制最末为 1
        result = multiply_matrix(result, M);
      }
      M = multiply_matrix(M, M);
      n = n >> 1;
    }
    return result;
  }

  int fib_2(int n) {
    if (n < 2) {
      return n;
    }
    vector<vector<long long>> M = {{1, 1}, {1, 0}};
    vector<vector<long long>> M_n = pow_matrix(M, n - 1);
    int result = (int)M_n[0][0];
    return result;
  }
};

int main() {
  int n = 46;

  Solution n1;
  int ans = n1.fib(n);
  int ans2 = n1.fib_2(n);

  cout << ans << endl
       << ans2 << endl;

  return 1;
}