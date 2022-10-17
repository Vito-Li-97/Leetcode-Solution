
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isHappy(int n) {  // hash
    unordered_set<int> visited;
    while (n != 1) {
      visited.insert(n);
      int sum = 0;
      while (n > 0) {
        int tmp = n % 10;  // 该位的数
        sum += tmp * tmp;
        n = n / 10;
      }
      n = sum;
      if (visited.count(n)) {
        return false;
      }
    }
    return true;
  }

  int digitsSquareSum(int n) {  // 得到每位数平方之和
    int sum = 0;
    while (n > 0) {
      int tmp = n % 10;
      sum += tmp * tmp;
      n = n / 10;
    }
    return sum;
  }
  bool isHappy_1(int n) {                     // 快慢指针可以用于找循环
    int slow = n, fast = digitsSquareSum(n);  // 可以不从同一起点出发，也迟早会追上，因为二者的距离每次变化一
    while (slow != fast) {                    // slow与fast相等时说明有循环，但有可能均为1
      slow = digitsSquareSum(slow);
      fast = digitsSquareSum(digitsSquareSum(fast));
    }
    return (slow == 1);  // 只要有1就说明快乐
  }

  // 1 <= n <= 2^31 - 1，数学分析，随后的值必 <= 243
  // 找出 n = [1, 243] 的所有处理后结果作为集合
  vector<int> allHappy() {
    vector<int> nums;
    for (int i = 1; i < 243 + 1; i++) {
      int k = i;
      for (int j = 0; j < 20; j++) {
        k = digitsSquareSum(k);
      }
      nums.push_back(k);
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    return nums;
  }

  bool isHappy_2(int n) {
    vector<int> nums = {1, 4, 16, 37, 58, 89, 145, 42, 20};
    vector<int>::iterator it;
    do {
      it = find(nums.begin(), nums.end(), n);
      n = digitsSquareSum(n);
    } while (it == nums.end());
    return n == 1;
  }
};

int main() {
  Solution solve;

  vector<int> allHappyNum = solve.allHappy();
  for (const auto& s : allHappyNum) {
    cout << s << endl;
  }

  cout << "solve: " << solve.isHappy_2(19) << endl;

  return 0;
}