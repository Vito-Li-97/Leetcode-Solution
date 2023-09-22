
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    int result = 0;
    unordered_map<char, int> stringmap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    for (int i = 0; i < s.size(); i++) {
      int value = stringmap[s[i]];
      if (i < s.size() - 1 && value < stringmap[s[i + 1]]) {
        result -= value;
      } else {
        result += value;
      }
    }

    return result;
  }
};

int main() {
  string digits = "MCMXCIV";

  Solution solve;
  int ans = solve.romanToInt(digits);

  cout << ans << endl;

  return 0;
}