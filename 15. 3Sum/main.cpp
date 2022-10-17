

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {  // hash set
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
  auto result = solve.threeSum(nums);

  return 0;
}