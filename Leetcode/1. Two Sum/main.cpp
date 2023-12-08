
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    // 方法：暴力枚举
    int len = nums.size();
    for (int i = 0; i < len - 1; i++) {
      for (int j = i + 1; j < len; j++) {
        if (nums[i] + nums[j] == target) {
          vector<int> res = {i, j};
          return res;
        }
      }
    }

    return {};
  }

  vector<int> twoSum_1(vector<int>& nums, int target) {
    // 方法：哈希表
    unordered_map<int, int> map1;
    int len = nums.size();

    for (int i = 0; i < len; i++) {
      unordered_map<int, int>::const_iterator got = map1.find(target - nums[i]);
      if (got == map1.end()) {
        map1.emplace(nums[i], i);
      } else {
        return {i, got->second};
      }
    }

    return {};
  }
};

int main() {
  vector<int> v1 = {2, 7, 11, 15};
  vector<int> v2 = {5, 6, 4, 9};

  Solution solve;
  auto result = solve.twoSum(v1, 9);

  return 0;
}