#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    // 暴力枚举
    int len = prices.size();
    int maxprofit = 0;
    for (int i = 0; i < len - 1; i++) {
      for (int j = i + 1; j < len; j++) {
        maxprofit = max(maxprofit, prices[j] - prices[i]);
      }
    }

    return maxprofit;
  }

  int maxProfit_1(vector<int>& prices) {
    // 动态规划
    int maxprofit = 0;
    int minprice = prices[0];
    for (int price : prices) {          // 逐步遍历
      minprice = min(minprice, price);  // 从开始到该点的最小price
      maxprofit = max(price - minprice, maxprofit);
      // 该点卖出的最大利润，与之前的最大利润，二者进行比较
    }

    return maxprofit;
  }
};

int main() {
  vector<int> nums = {7, 1, 5, 3, 6, 4};

  Solution solve;
  auto result = solve.maxProfit_1(nums);
  cout << result << endl;

  return 0;
}