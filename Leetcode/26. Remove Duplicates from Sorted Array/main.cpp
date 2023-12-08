#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int len = nums.size();
    int slow = 0;
    for (int fast = 1; fast < len; fast++) {
      if (nums[fast] != nums[fast - 1]) {
        slow++;
        nums[slow] = nums[fast];
      }
    }

    return slow + 1;
  }
};

int main() {
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

  Solution solve;
  auto result = solve.removeDuplicates(nums);
  cout << result << endl;

  return 0;
}