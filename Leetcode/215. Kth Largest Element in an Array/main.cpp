#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  //基于快速排序的选择方法
  int quickSelect(vector<int>& nums, int left, int right, int k) {
    // 对于nums[left~right]进行从小到大的快速排序，直到划分后轴点位置正好为k
    if (left == right) {  // 如果仅有一个元素
      return nums[k];
    }

    int pivot = nums[left], i = left - 1, j = right + 1;
    while (i < j) {  // 双指针，i向右扩展小于轴点区间，j向左扩展大于轴点区间
      do {           // i++，如果nums[i]<pivot，则继续i++直到nums[i]>=pivot
        i++;
      } while (nums[i] < pivot);
      do {  // j++，如果nums[j]>pivot，则继续j++直到nums[j]<=pivot
        j--;
      } while (nums[j] > pivot);
      // 此时nums[left~i-1]<pivot, nums[i]>= pivot,
      // nums[j+1~right]>pivot, nums[j]<= pivot
      if (i < j) {
        swap(nums[i], nums[j]);
      }
    }
    // 此时i=j或i=j+1

    // 此处划分区间需注意
    // 最左为轴点时取[left,j], [j+1, right],因为可能有i=j=left
    // 最右为轴点时取[left,i-1], [i, right],因为可能有i=j=right
    if (k <= j) {  // 递归左区间
      return quickSelect(nums, left, j, k);
    } else {  // 递归右区间
      return quickSelect(nums, j + 1, right, k);
    }
  }

  int findKthLargest(vector<int>& nums, int k) {
    //求第 k 个最大的元素，即从小到大排序后nums[len-k]
    int len = nums.size();
    return quickSelect(nums, 0, len - 1, len - k);
  }
};

class Solution_1 {
 public:
  // 方法：基于堆排序的选择方法
  void maxHeapify(vector<int>& A, int k, int heapSize) {
    // 堆A的最大序号为heapSize，默认k节点的子节点的子树均为最大堆
    // 使得k节点的值大于子节点，k为根的子树为最大堆
    int lI = 2 * k + 1;  // 注意堆序号是从0还是1开始
    int rI = 2 * k + 2;
    int largestI = k;
    if (lI <= heapSize - 1 && A[lI] >= A[largestI]) {
      // 子节点的序号不可超出堆的最大序号
      largestI = lI;
    }
    if (rI <= heapSize - 1 && A[rI] >= A[largestI]) {
      largestI = rI;
    }
    if (largestI != k) {
      swap(A[largestI], A[k]);
      maxHeapify(A, largestI, heapSize);
      // 检查变化的子节点
    }
  }

  void buildMaxHeap(vector<int>& nums, int heapSize) {
    // 自底向上，将数组[0, heapSize-1]转化为最大堆
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
      // 从有子节点，且下标最大的节点开始
      maxHeapify(nums, i, heapSize);
    }
  }

  int findKthLargest(vector<int>& nums, int k) {
    int heapSize = nums.size();    // 堆的容量，对应数组[0, heapSize-1]
    buildMaxHeap(nums, heapSize);  // 建立最大堆
    for (int i = 0; i < k - 1; i++) {
      swap(nums[0], nums[heapSize - 1]);
      //将最顶部元素nums[0]，即堆内最大值，与数组末尾元素交换
      heapSize--;
      // heapSize--
      maxHeapify(nums, 0, heapSize);
      // 从排列最大堆，使得nums[0]为堆内最大元素
    }

    return nums[0];
  }
};

int main() {
  vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  int k = 4;

  Solution_1 solve;
  auto result = solve.findKthLargest(nums, k);
  cout << result << endl;

  return 0;
}