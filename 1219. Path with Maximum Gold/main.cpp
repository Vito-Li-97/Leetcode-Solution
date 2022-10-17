#include <iostream>
using namespace std;
#include <vector>

#include "solution_ljc.h"

////////////////////////////////////////////////////////////////////////////////////
int main() {
  Solution solution;  // 声明类
  int result;
  vector<vector<int>> grid1 = {{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
  vector<vector<int>> grid2 = {{1, 0, 7}, {2, 0, 6}, {3, 4, 5}, {0, 3, 0}, {9, 0, 20}};

  cout << solution.getMaximumGold(grid1) << endl;
  cout << solution.getMaximumGold(grid2) << endl;

  return 0;
}