
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    vector<int> record(128, 0);  // ASCII
    int n = s.size();
    int len = 0;
    int sub_start = 0;
    int sub_end = 0;
    while (sub_start < n && sub_end < n) {
      if (record[(int)s[sub_end]] > 0) {
        // 若 sub_end 与前面重复了，sub_start++，并抹去sub_start经过的地方
        // 直到 sub_end 不与 sub 重复
        record[(int)s[sub_start]] = 0;
        sub_start++;
      } else {
        // sub_end用来记录
        record[(int)s[sub_end]] = 1;
        len = max(sub_end - sub_start + 1, len);
        sub_end++;
      }
    }
    return len;
  }

  int lengthOfLongestSubstring_1(string s) {
    unordered_set<char> record;
    int n = s.size();
    int len = 0;
    int sub_start = 0;
    int sub_end = 0;

    while (sub_start < n && sub_end < n) {
      if (record.find(s[sub_end]) != record.end()) {
        // 若 sub_end 与前面重复了，sub_start++，并抹去sub_start经过的地方
        // 直到 sub_end 不与 sub 重复
        record.erase(s[sub_start]);
        sub_start++;
      } else {
        // sub_end用来记录
        record.insert(s[sub_end]);
        len = max(sub_end - sub_start + 1, len);
        sub_end++;
      }
    }

    return len;
  }
};

int main() {
  string s = "abcabcbb";

  Solution solve;
  cout << solve.lengthOfLongestSubstring(s) << endl
       << solve.lengthOfLongestSubstring_1(s) << endl;

  return 0;
}