

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x == 0) {
      return true;
    }
    if (x < 0 || x % 10 == 0) {
      return false;
    }

    // 数字的后半部分，反转，与前半部分是否一致
    int revertedNumber = 0;
    while (revertedNumber < x) {
      revertedNumber *= 10;
      revertedNumber += x % 10;
      x = x / 10;
    }

    return revertedNumber == x || revertedNumber / 10 == x;
  }
};

int main() {
  int nums = 19971179911;

  Solution solve;
  auto result = solve.isPalindrome(nums);
  cout << result << endl;

  return 0;
}