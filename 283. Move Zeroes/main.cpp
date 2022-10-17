
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {  // 一次遍历
    int n = nums.size();
    if (n < 2) {
      return;
    }

    int slow = 0, fast = 0;
    while (fast < n) {        // fast 遍历到底
      if (nums[fast] != 0) {  // 只要nums[fast]!=0，我们就交换nums[slow]和nums[fast]
        swap(nums[slow], nums[fast]);
        slow++;
      }
      fast++;
    }
  }

  void moveZeroes_1(vector<int>& nums) {  // 两次遍历，后续补0
    int n = nums.size();
    if (n < 2) {
      return;
    }

    int slow = 0, fast = 0;
    while (fast < n) {
      if (nums[fast] != 0) {  // 变换后slow++
        nums[slow] = nums[fast];
        slow++;
      }
      fast++;
    }

    for (int i = slow; i < n; i++) {
      nums[i] = 0;
    }
  }
};

int main() {
  vector<int> v1 = {4, 2, 4, 0, 0, 3, 0, 5, 1, 0};

  Solution solve;
  solve.moveZeroes_1(v1);

  for (auto& elem : v1) {
    cout << elem << " ";
  }

  return 0;
}