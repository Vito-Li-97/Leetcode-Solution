
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
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
};

int main() {
  int n = 100;

  Solution n1;
  int ans = n1.fib(100);

  cout << ans << ' ';

  return 1;
}