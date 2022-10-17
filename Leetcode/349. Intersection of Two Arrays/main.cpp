
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {  // unordered_set
    unordered_set<int> result_set;                                    // 用set是为了给结果集去重
    unordered_set<int> nums_set(nums1.begin(), nums1.end());          // unordered_set得到无重复元素的集合
    for (int num : nums2) {                                           // 检查nums2的每个元素，是否在nums_set里出现
      if (nums_set.find(num) != nums_set.end()) {                     // returns an iterator to it if found
        result_set.insert(num);                                       // otherwise returns an iterator to unordered_set::end
      }
    }
    return vector<int>(result_set.begin(), result_set.end());
  }

  vector<int> intersection_1(vector<int>& nums1, vector<int>& nums2) {  //用数组来做哈希表
    unordered_set<int> result_set;
    int hash[1005] = {0};    // 默认数值为0
    for (int num : nums1) {  // nums1中出现的字母在hash数组中做记录
      hash[num] = 1;
    }
    for (int num : nums2) {  // nums2中出现话，result记录
      if (hash[num] == 1) {
        result_set.insert(num);
      }
    }
    return vector<int>(result_set.begin(), result_set.end());
  }
};

int main() {
  vector<vector<int>> nums{
      {1, 2, 2, 1},
      {2, 2},
      {4, 9, 5},
      {9, 4, 9, 8, 4}};

  Solution solve;
  for (int i = 0; i < nums.size(); i += 2) {
    for (const auto& s : solve.intersection(nums[i], nums[i + 1])) {
      cout << s << " ";
    }
    cout << endl;
  }
  return 0;
}