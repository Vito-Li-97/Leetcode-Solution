
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int preimageSizeFZF(int k) {  // 二分搜索，判断 l 的5因子数是否等于 k 即可
    long l = k - 1, r = k * 10L + 1;
    while (l + 1 < r) {
      long m = l + r >> 1, t = f(m);
      if (t == k)
        return 5;
      else if (t < k)
        l = m;
      else
        r = m;
    }
    return 0;
  }
  long f(long n) {  // 递归，统计 n! 的5因子个数
    if (n == 0) {   // floor(n/5^i) 为至少有 i 个5因子的数的个数，一层一层累加起来为因子个数
      return 0;
    }
    return n / 5 + f(n / 5);
  }
};

int main() {
  int k = 38995104;
  Solution solve;
  cout << solve.preimageSizeFZF(k) << endl;

  return 0;
}