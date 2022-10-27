
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {  // 和为s的两个数字
 public:
  // 双指针法
  // O(n)
  // O(1)
  vector<int> twoSum(vector<int>& nums, int target) {
    int a = 0, b = nums.size() - 1;
    vector<int> res;

    while (a < b) {
      int sum = nums[a] + nums[b];
      if (sum < target) {
        a++;
      } else if (sum > target) {
        b--;
      } else {
        res.push_back(nums[a]);
        res.push_back(nums[b]);
        return res;
      }
    }
    return res;
  }

  // 哈希表
  // O(n)
  // O(n)
  vector<int> twoSum_2(vector<int>& nums, int target) {
    vector<int> result;
    unordered_set<int> use;

    for (int i = 0; i < nums.size(); i++) {
      if (use.find(nums[i]) == use.end()) {
        use.insert(target - nums[i]);
      } else {
        result.push_back(nums[i]);
        result.push_back(target - nums[i]);
        return result;
      }
    }

    return result;
  }
};

int main() {
  vector<int> test = {2, 7, 11, 15};
  int target = 9;

  Solution n1;
  vector<int> vec = n1.twoSum(test, target);
  vector<int> vec2 = n1.twoSum_2(test, target);

  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << ' ';
  }
  cout << endl;
  for (int i = 0; i < vec2.size(); i++) {
    cout << vec2[i] << ' ';
  }

  return 1;
}