
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {  // 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 public:
  bool isAnagram(string s, string t) {
    int record[26] = {0};
    for (int i = 0; i < s.size(); i++) {
      record[s[i] - 'a']++;  // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
    }
    for (int i = 0; i < t.size(); i++) {
      record[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {  // 判断s和t的相对值
      if (record[i] != 0) {
        return false;  // record数组如果有的元素不为 0，说明字符串 s和t 一定是谁多了字符或者谁少了字符。
      }
    }
    return true;  // record数组所有元素都为 0，说明字符串s和t是字母异位词
  }

  bool isAnagram_1(string s, string t) {  // 容器版
    if (s.length() != t.length()) {
      return false;
    }
    vector<int> table(26, 0);
    // for(auto a:b)中b为一个容器，效果是利用a遍历并获得b容器中的每一个值，但是a无法影响到b容器中的元素。
    // for(auto &a:b)中加了引用符号，可以对容器中的内容进行赋值，即可通过对a赋值来做到容器b的内容填充。
    for (auto& ch : s) {
      table[ch - 'a']++;
    }
    for (auto& ch : t) {
      table[ch - 'a']--;
      if (table[ch - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }

  bool isAnagram_2(string s, string t) {  // 排序，sort 将s和t排序，看是否相等
    if (s.length() != t.length()) {
      return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
  }
};

int main() {
  vector<string> args = {
      "anagram",
      "nagaram",
      "rat",
      "car"};

  Solution solve;
  for (int i = 0; i < args.size(); i += 2) {
    cout << solve.isAnagram_1(args[i], args[i + 1]) << endl;
  }
  return 0;
}