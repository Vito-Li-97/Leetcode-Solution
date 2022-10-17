
#include <iostream>
using namespace std;

class Solution {  // 返回其二进制表达式中数字位数为 '1' 的个数（也被称为汉明重量）。
 public:
  int hammingWeight(uint32_t n) {  // normal method
    int c = 0;
    for (c = 0; n; n >>= 1) {
      c += (n & 1);
    }
    return c;
  }
  int hammingWeight_1(uint32_t n) {  // fast method
    int c = 0;
    while (n) {
      c++;
      n &= n - 1;  //与运算，消除最右边的1
      // 当 x 为奇数时，减 1 很容易：您只需清除最后的 1 位就可以了。
      // 当 x 不是奇数时，您需要从相邻位“借用”，这会导致潜在的级联借用，直到找到可以借用的 1 位。
      // 这意味着从最右（x 的最低有效位）开始，逐位变1，直到遇到第一个 1 位，然后将其变 0。
    }
    return c;
  }
  int hammingWeight_2(uint32_t n) {  // GCC function
    return __builtin_popcount(n);
  }
};

int main() {
  uint32_t x = 0b11111111111111111111111111111101;
  Solution sol;
  cout << sol.hammingWeight(x) << endl
       << sol.hammingWeight_1(x) << endl
       << sol.hammingWeight_2(x) << endl;
}