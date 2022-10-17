#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    vector<int> ans(n);
    stack<int> st;  //建立一个单调递增栈，栈里面的元素都是没找到小于等于自己的元素的。
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && st.top() > prices[i]) {
        st.pop();  // 若prices[i] 小于 top，则将 top 弹出
      }
      ans[i] = st.empty() ? prices[i] : prices[i] - st.top();
      st.emplace(prices[i]);
    }
    return ans;
  }
};

int main() {
  vector<int> prices = {8, 4, 6, 2, 3};

  Solution solution;  // 声明类
  solution.finalPrices(prices);
  for (const auto& elem : prices) {
    cout << elem << endl;
  }

  return 0;
}