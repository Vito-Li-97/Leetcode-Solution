#include <iostream>
using namespace std;

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    // 2的幂次方恒大于0
    if (n <= 0)
      return false;
    while (n != 0)  // 2的幂最后变为1，再变为0
    {
      if (n % 2 == 1 && n != 1)
        return false;
      else
        n /= 2;
    }
    return true;
  }
};

int main() {
  Solution n1;
  for (int a = 1; a < 100; a = a + 1)
    cout << a << "  " << n1.isPowerOfTwo(a) << '\n';
  return 0;
}