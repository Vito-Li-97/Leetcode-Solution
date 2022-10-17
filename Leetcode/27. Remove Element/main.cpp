#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int removeElement_1(vector<int>& nums, int val) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] == val) {
        for (int j = i; j < n - 1; j++) {
          nums[j] = nums[j + 1];
        }
        n--;
        i--;
      }
    }
    return n;
  }

  int removeElement_2(vector<int>& nums, int val) {
    //双指针法
    //右指针指向当前将要处理的元素，左指针指向输出数组中要赋值的位置。
    //如果右指针指向的元素不等于 val，它一定是输出数组的一个元素，
    //我们就将右指针指向的元素复制到左指针位置，然后将左右指针同时右移；
    //如果右指针指向的元素等于 val，此时左指针不动，右指针右移一位。
    int n = nums.size();
    int slow = 0;
    for (int fast = 0; fast < n; fast++) {  // fast++
      if (nums[fast] != val) {
        nums[slow++] = nums[fast];  // copy and slow++
      }
    }
    return slow;
  }

  int removeElement_3(vector<int>& nums, int val) {
    int left = 0;
    int right = nums.size() - 1;  // consider num.size()=0 or 1
    while (left <= right) {
      if (nums[left] == val) {
        // if left=val，copy right to left
        // right--
        nums[left] = nums[right];
        right--;
      } else {
        // if left!=val，left++
        // The last time left adds an extra 1
        left++;
      }
    }
    return left - 1 + 1;  // output array's final position = left-1, length = left-1+1
  }
};

int main() {
  Solution n1;
  vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
  int val = 2;
  int k1 = n1.removeElement_3(nums, val);
  cout << "k1=" << k1 << '\n';
  return 0;
}