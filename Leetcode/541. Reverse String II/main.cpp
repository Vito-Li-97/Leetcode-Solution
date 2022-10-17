
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  void reverseStr_part(string &s, int n_begin, int n_end) {  // reverse part of string
    for (int i = 0; i < (n_end - n_begin + 1) / 2; i++) {
      swap(s[n_begin + i], s[n_end - i]);
    }
  }

  string reverseStr(string s, int k) {  // 对string默认 值引用
    int len = s.size();
    int n = len / (2 * k);
    for (int i = 0; i < len - 2 * k + 1; i += 2 * k) {  // len-1-i+1 >= 2*k 即[i,len-1]至少有2k个元素
      reverseStr_part(s, i, i + k - 1);
    }
    reverseStr_part(s, 2 * k * n, min(len - 1, 2 * k * n + k - 1));
    return s;
  }

  string reverseStr_1(string s, int k) {                    // using reverse
    int len = s.size();                                     // 迭代器类型不是int
    for (int i = 0; i < len; i += 2 * k) {                  // 指针每次移动2k
      reverse(s.begin() + i, s.begin() + min(len, k + i));  // 判断（与末尾距离，k）的最小值
      // reverse [first,last)
    }
    return s;
  }
};

int main() {
  string s = "abcdefg";
  int k = 2;

  Solution solve;
  cout << solve.reverseStr(s, k) << endl;
  cout << solve.reverseStr_1(s, k) << endl;

  return 0;
}