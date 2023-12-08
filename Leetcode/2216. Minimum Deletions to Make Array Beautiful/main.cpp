#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int minDeletion(vector<int>& nums) {  //三叶的解法
    int cnt = 0;
    int len = nums.size();

    if (len == 1) {
      return 1;
    }

    for (int i = 0; i < len - 1; i++) {
      if ((i - cnt) % 2 == 0 && nums[i] == nums[i + 1]) {
        //原数组下标i，在新数组中的下标为i-cnt
        cnt++;
      }
    }

    if ((len - cnt) % 2 == 1) {
      cnt++;
    }
    return cnt;
  }
};

int main() {
  vector<int> nums = {1, 1, 2, 2, 3, 3};

  Solution solve;
  auto result = solve.minDeletion(nums);
  cout << result << endl;

  return 0;
}