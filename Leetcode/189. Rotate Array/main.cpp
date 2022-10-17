
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {  // 给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
 public:
  void rotate(vector<int>& nums, int k) {
    int len = nums.size();
    int part = k - k / len * len;  // 把 k 化为 [0, len-1]

    vector<int> tmp(nums.begin(), nums.end());
    for (int i = 0; i < part; i++) {
      nums[i] = tmp[len - part + i];
    }
    for (int i = 0; i < len - part; i++) {
      nums[part + i] = tmp[i];
    }
  }

  void rotate_1(vector<int>& nums, int k) {  // 环状替换
    int n = nums.size();
    int kn = k % n;

    int count = 0;                  // 或是定义count = gcd(n,kn)，为i循环的次数
    for (int i = 0; i < kn; i++) {  // 选一个起点
      int i1 = i;
      int tmp = nums[i1];
      do {                       // 每圈访问 lcm(k,n)/k 个元素
        int i2 = (i1 + kn) % n;  // i1 变换后的位置
        swap(tmp, nums[i2]);     // tmp与每个变动的元素交换值，相当于整体平移
        i1 = i2;
        count++;
      } while (i1 != i);  // 若i1再次回到起点i，则停止循环
      if (count == n) {   // 当移动的元素等于n
        break;
      }
    }
  }

  void rotate_2(vector<int>& nums, int k) {  // reverse
    int n = nums.size();                     // 原本 [0, n-k-1], [n-k, n-1]
    int kn = k % n;
    reverse(nums.begin(), nums.end());  // [n-1, n-k], [n-k-1, 0]
    reverse(nums.begin(), nums.begin() + kn);
    reverse(nums.begin() + kn, nums.end());
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  int k = 3;

  Solution solve;
  solve.rotate_2(nums, k);
  for (const auto& n : nums) {
    cout << n << endl;
  }

  return 0;
}