

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    // 方法：排序 + 双指针 O(N^2) O(logN) (快速排序的空间复杂度)
    int len = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());  // 将nums从小到大排序

    // 枚举 a
    for (int first = 0; first < len; first++) {
      if (first > 0 && nums[first - 1] == nums[first]) {
        // 和前一个枚举元素不相同时才进行下一层枚举，否则跳过
        continue;
      }
      int third = len - 1;  // c从最右左移，逐步减小
      for (int second = first + 1; second < len; second++) {
        if (second > first + 1 && nums[second - 1] == nums[second]) {
          // 和前一个枚举元素不相同时才进行下一层枚举，否则跳过该元素
          continue;
        }

        // 左指针小于右指针且三数和大于0时，右指针左移
        // 最终让右指针使得，三数和为满足<=0的最大值
        while (second < third && nums[first] + nums[second] + nums[third] > 0) {
          third--;
        }

        // 左右指针重合时才有三数和<0，说明最小的三数和都>0
        // 则该层没有满足条件的c，循环中断
        if (second == third) {
          break;
        }

        if (nums[first] + nums[second] + nums[third] == 0) {
          vector<int> cache = {nums[first], nums[second], nums[third]};
          res.push_back(cache);
        }
      }
    }

    return res;
  }

  vector<vector<int>> threeSum_1(vector<int>& nums) {
    // 方法：hash set
    int n = nums.size();
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());  // 排序

    for (int i = 0; i <= n - 3; i++) {
      // 找出a + b + c = 0
      // a = nums[i], b = nums[j], c = -(a + b)
      if (nums[i] > 0) {  // a > 0 则不存在对应 b, c
        break;
      }
      if (i > 0 && nums[i - 1] == nums[i]) {
        // 对 nums[i] = {a1 a2 a3...} 去重，重复元素里只留第一个 a 的结果
        // 因为 nums[i] = a1 的结果包含后面所有 nums[i] = {a2 a3...} 的结果
        continue;
      }
      unordered_set<int> record;
      for (int j = i + 1; j < n; j++) {
        if (j >= i + 3 && nums[j - 1] == nums[j] && nums[j - 2] == nums[j - 1]) {
          // 对 nums[j] = {b1 b2 b3...} 去重，只遍历 b1 b2
          continue;
        }
        // unordered_set 记录遍历过的 b 作为备选 c，检查当下的 b = nums[j] 是否可取前面的某个 b 作为 c
        int c = 0 - (nums[i] + nums[j]);
        if (record.find(c) == record.end()) {
          // 如果当下的 b 找不到相应的 c，则将当下 b 作为 c 放入 set。
          record.insert(nums[j]);
        } else {
          // 如果当下的 b 找不到相应的 c，则找到一组 a b c
          // 对 c 去重， 将 record set 里已使用的 c 删掉
          result.push_back({nums[i], nums[j], c});
          record.erase(c);
        }
      }
    }

    return result;
  }
};

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  nums = {-2, 0, 1, 1, 2};
  nums = {-2, 0, 0, 2, 2};

  Solution solve;
  vector<vector<int>> result = solve.threeSum(nums);

  return 0;
}