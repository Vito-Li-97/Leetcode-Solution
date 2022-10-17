
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // 简单粗暴，先将两个数组合并，两个有序数组的合并也是归并排序中的一部分。
    // 然后根据奇数，还是偶数，返回中位数。
    int m = nums1.size();
    int n = nums2.size();
    vector<int> nums(m + n, 0);
    if (m == 0) {
      if (n % 2 == 0) {
        return (nums2[n / 2 - 1] + nums2[n / 2]) / 2.0;
      } else {
        return nums2[n / 2];
      }
    }
    if (n == 0) {
      if (m % 2 == 0) {
        return (nums1[m / 2 - 1] + nums1[m / 2]) / 2.0;
      } else {
        return nums1[m / 2];
      }
    }

    // 双指针遍历两个数组，将其从小到大排序到新数组上
    // 若有数组已经被遍历完，将另一个数组的剩余部分放到新数组上
    int count = 0;
    int i = 0, j = 0;
    while (count < m + n) {
      if (i == m && j != n) {
        for (int k = j; k < n; k++) {
          nums[count++] = nums2[k];
        }
        break;
      }
      if (j == n && i != m) {
        for (int k = i; k < m; k++) {
          nums[count++] = nums1[k];
        }
        break;
      }

      if (nums1[i] < nums2[j]) {
        nums[count++] = nums1[i++];
      } else {
        nums[count++] = nums2[j++];
      }
    }

    double result = 0;
    if ((m + n) % 2 == 1) {  // 数组长度奇数，中位数为正中间元素；偶数为中间两个的平均值
      result = nums[(m + n) / 2];
    } else {
      result = (nums[(m + n) / 2 - 1] + nums[(m + n) / 2]) / 2.0;
    }

    return result;
  };
};

int main() {
  vector<int> nums1 = {1, 2};
  vector<int> nums2 = {3, 4};

  Solution solve;
  double ans = solve.findMedianSortedArrays(nums1, nums2);

  cout << ans << endl;

  return 0;
}