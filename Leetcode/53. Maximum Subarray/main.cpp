#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    // 方法：动态规划 O(n),O(n)
    int maxAns;
    int len = nums.size();
    vector<int> ff(len);

    ff[0] = nums[0];
    maxAns = ff[0];
    for (int i = 1; i < len; i++) {
      ff[i] = max(ff[i - 1] + nums[i], nums[i]);
      maxAns = max(maxAns, ff[i]);
    }
    return maxAns;
  }

  int maxSubArray_1(vector<int>& nums) {
    // 方法：动态规划，滚动数组 O(n),O(1)
    int len = nums.size();
    int maxAns = nums[0];
    int pre = nums[0];  //变量pre表示对于当前 f(i)的 f(i−1)的值是多少
    for (int i = 1; i < len; i++) {
      pre = max(pre + nums[i], nums[i]);
      // f(i) = max(f(i-1)+nums[i], nums[i])
      maxAns = max(maxAns, pre);
      // max(f(0~i)) = max(max(f(0~i-1)), f(i))
    }
    return maxAns;
  }

  int maxSubArray_2(vector<int>& nums) {
    // 前缀和之差的最大值，即求Si-Sj的最大值，即股票交易
    int len = nums.size();
    int partialSum = 0;     // S(0)
    int minPartialSum = 0;  // minS(0)
    int maxDiff = INT_MIN;  // D(0)
    for (int i = 0; i < len; i++) {
      partialSum += nums[i];
      maxDiff = max(maxDiff, partialSum - minPartialSum);
      minPartialSum = min(minPartialSum, partialSum);
    }
    return maxDiff;
  }
};

int main() {
  vector<int> nums = {5, 4, -1, 7, 8};

  Solution solve;
  auto result = solve.maxSubArray_2(nums);
  cout << result << endl;

  return 0;
}