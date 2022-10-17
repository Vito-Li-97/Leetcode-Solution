
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
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

  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << ' ';
  }

  return 1;
}