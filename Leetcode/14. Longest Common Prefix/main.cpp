#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    // 取最短的字符串，
  }
};

int main() {
  vector<string> strs = {"flower", "flow", "flight"};

  Solution solve;
  auto result = solve.longestCommonPrefix(strs);
  cout << result << endl;

  return 0;
}