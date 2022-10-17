
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {  // 给你一个字符串 s ，请你反转字符串中 单词 的顺序。
 public:
  string reverseWords(string s) {  // no reverse, two pointers
    vector<string> temp1;

    int word_len = 0;
    int s_p = 0;    // 处理后的s的长度位置指针
    int cache = 0;  // 判断是否有 word 要处理
    s.push_back(' ');
    for (int i = 0; i < s.length(); i++) {
      if (s[i] != ' ') {  // 读取 word 时
        cache = 1;
        word_len++;
      } else if (cache != 0) {                     // 遇到第一个空格时
        for (int k = 0; k < (i - s_p) / 2; k++) {  // 将刚读完的 word 反转放置到s对应前部
          swap(s[s_p + k], s[i - 1 - k]);
        }
        s_p += word_len + 1;  // s_p位于下一个word的首位
        word_len = 0;
        cache = 0;
      }
    }
    s.resize(--s_p);  // s_p-1 为新向量长度

    for (int i = 0; i < s_p / 2; i++) {  // reverse s
      swap(s[i], s[s_p - 1 - i]);
    }

    return s;
  }
};

int main() {
  string input = "hello    world";

  Solution solve;
  string result = solve.reverseWords(input);
  cout << endl;
  for (const auto &elem : result) {
    cout << elem;
  }
  cout << "@";

  return 0;
}