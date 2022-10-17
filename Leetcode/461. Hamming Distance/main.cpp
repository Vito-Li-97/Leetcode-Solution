
#include <iostream>
using namespace std;

class Solution {
 public:
  int binaryOneNum(int x) {  // 快速位与法
    int c = 0;
    for (c = 0; x > 0; ++c) {
      x &= (x - 1);  // 与运算，清除  最低位的1
    }
    return c;
  }
  int hammingDistance(int x, int y) {
    return binaryOneNum(x ^ y);  // 异或运算符，得到不同的位
  }
};

int main() {
  int x = 205, y = 105;
  Solution sol;
  cout << sol.hammingDistance(x, y) << endl;
}