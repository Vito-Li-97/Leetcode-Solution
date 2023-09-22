#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int minCount(vector<int>& coins) {
    int res = 0;
    for (int i = 0; i < coins.size(); i++) {
      res += (coins[i] + 1) / 2;
    }
    return res;
  }

  int minCount_1(vector<int>& coins) {
    int res = 0;
    for (int coin : coins) {
      res += (coin + 1) / 2;
    }
    return res;
  }

  int minCount_2(vector<int>& coins) {
    int res = 0;
    for (auto coin : coins) {
      res += (coin + 1) / 2;
    }
    return res;
  }
};

int main() {
  Solution n1;
  vector<int> nums = {4, 1, 2, 2, 3, 10, 4, 2};
  int k1 = n1.minCount(nums);
  int k2 = n1.minCount_1(nums);
  int k3 = n1.minCount_2(nums);
  cout << "k1 = " << k1 << '\n'
       << "k1 = " << k2 << '\n'
       << "k1 = " << k3 << '\n';

  return 0;
}