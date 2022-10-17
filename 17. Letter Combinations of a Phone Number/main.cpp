
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {  // 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
                  //答案可以按 任意顺序 返回。
 public:
  const unordered_map<char, string> umap{{'2', "abc"},
                                         {'3', "def"},
                                         {'4', "ghi"},
                                         {'5', "jkl"},
                                         {'6', "mno"},
                                         {'7', "pqrs"},
                                         {'8', "tuv"},
                                         {'9', "wxyz"}};
  vector<string> result;
  string temp;

  void dfs(string digits, int index) {  // 回溯递归
    if (index == digits.size()) {       // index 记录遍历了digits的第几个数字
      result.push_back(temp);
      return;  // 遍历个数index达到目标个数时return
    }

    string correspond_num = umap.at(digits[index]);  // 取数字对应的字符集

    for (int i = 0; i < correspond_num.size(); i++) {  // 先横向遍历当前字符集，每次取一个元素
      temp.push_back(correspond_num[i]);               // 放入temp
      dfs(digits, index + 1);                          // 节点处，纵向遍历，进行下一层选择
      temp.pop_back();                                 // 回溯，删除上一个元素
    }
    return;
  }

  vector<string> letterCombinations(string digits) {  // hashmap and backtracking
    result.clear();
    temp.clear();
    if (digits.size() == 0) {
      return result;
    }

    dfs(digits, 0);
    return result;
  }
};

class Solution_1 {
 public:
  const string letterMap[10] = {
      "",      // 0
      "",      // 1
      "abc",   // 2
      "def",   // 3
      "ghi",   // 4
      "jkl",   // 5
      "mno",   // 6
      "pqrs",  // 7
      "tuv",   // 8
      "wxyz",  // 9
  };           // string array
  vector<string> result;

  void dfs(const string& digits, int index, const string& s) {  // 回溯递归
    if (index == digits.size()) {
      result.push_back(s);  // s储存当前的一个答案
      return;
    }

    int digit = digits[index] - '0';
    string letters = letterMap[digit];          // 获得数字对应的字符集
    for (int i = 0; i < letters.size(); i++) {  // 将回溯过程写在递归函数的参数里
      dfs(digits, index + 1, s + letters[i]);   // 注意这里的不同
                                                // s+letters[i]不改变s的值，相当于回溯
    }
    return;
  }

  vector<string> letterCombinations(string digits) {  // hashmap and backtracking
    result.clear();
    if (digits.size() == 0) {
      return result;
    }

    dfs(digits, 0, "");
    return result;
  }
};

int main() {
  string digits = "234";
  // digits = "";

  Solution_1 solve;
  vector<string> ans = solve.letterCombinations(digits);

  for (auto& elem : ans) {
    cout << elem << endl;
  }

  return 0;
}