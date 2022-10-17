
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    if (s.size() % 2 != 0) {
      return false;
    }

    stack<char> judge;

    for (int i = 0; i < s.size(); i++) {
      char tmp = s[i];
      if (tmp == '(') {  //遇到左括号时将对应的右括号放入栈顶，遇到右括号时检查是否和栈顶元素一样
        judge.push(')');
      } else if (tmp == '{') {
        judge.push('}');
      } else if (tmp == '[') {
        judge.push(']');
      } else if (!judge.empty() && judge.top() == tmp) {
        judge.pop();  // judge不为空且栈顶元素等于tmp
      } else {
        return false;
      }
    }

    return judge.empty();
  }

  bool isValid_1(string s) {  // hash-map
    int n = s.size();
    if (n % 2 != 0) {
      return false;
    }
    unordered_map<char, char> map1{
        {')', '('},
        {']', '['},
        {'}', '{'}};
    stack<char> judge;

    for (char elem : s) {
      if (map1.count(elem)) {
        // 遇到右括号时，检查其与最新的左括号是否对应
        if (judge.empty() || judge.top() != map1[elem]) {  // 若栈为空或栈顶不等于对应的左括号
          return false;
        }
        judge.pop();       // 若栈顶为对应的左括号，则弹出相应左括号
      } else {             // 遇到左括号时
        judge.push(elem);  // 将其放入栈顶。(后遇到的左括号要先闭合，栈顶为最新的左括号)
      };
    }
    return judge.empty();
  }
};

int main() {
  string s = "()[]{}";

  Solution solve;
  cout << solve.isValid_1(s) << endl;

  return 0;
}