
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int addDigits(int num) {  // 迭代
    while (num > 9) {
      int temp = 0;
      while (num > 0) {
        temp += num % 10;
        num /= 10;
      }
      num = temp;
    }
    return num;
  }

  int addDigits_1(int num) {  // recursion
    if (num < 10) {
      return num;
    }
    int temp = 0;
    while (num > 0) {
      temp += num % 10;
      num /= 10;
    }
    return addDigits_1(temp);
  }

  int addDigits_2(int num) {  // O(1)
    return (num - 1) % 9 + 1;
  }
};

int main() {
  int num = 114514;

  Solution solve;
  cout << solve.addDigits(num) << endl
       << solve.addDigits_1(num) << endl
       << solve.addDigits_2(num) << endl;

  return 0;
}