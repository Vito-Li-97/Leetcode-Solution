#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {  // 迭代法，遍历 nums 所有元素
    // 取空集作为初始子集群
    // 遇到一个元素就把已有的子集加上该元素组成新的子集
    // 将新子集加入子集群。遍历完毕即得到所有子集
    vector<vector<int>> ans({{}});
    for (int num : nums) {  // 遍历 nums 的每个元素为 num
      for (int i = ans.size() - 1; i >= 0; --i) {
        vector<int> tmp = ans[i];
        tmp.push_back(num);
        ans.push_back(tmp);
      }
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {1, 2, 3};
  Solution solve;
  auto ans = solve.subsets(nums);

  for (int i = 0; i < ans.size(); i++) {
    for (auto const& s : ans[i]) {
      cout << s << " ";
    }
    cout << endl;
  }
  return 0;
}
