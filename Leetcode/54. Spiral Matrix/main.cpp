
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> res(m * n, 0);
    int xl = 0, xm = m - 1, yl = 0, ym = n - 1;
    int num = 0;

    while (num < m * n) {
      for (int i = yl; num < m * n && i <= ym; i++) {
        res[num] = matrix[xl][i];
        num++;
      }
      xl++;
      for (int i = xl; num < m * n && i <= xm; i++) {
        res[num] = matrix[i][ym];
        num++;
      }
      ym--;
      for (int i = ym; num < m * n && i >= yl; i--) {
        res[num] = matrix[xm][i];
        num++;
      }
      xm--;
      for (int i = xm; num < m * n && i >= xl; i--) {
        res[num] = matrix[i][yl];
        num++;
      }
      yl++;
    }
    return res;
  }
};

int main() {
  vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Solution n1;
  vector<int> vec = n1.spiralOrder(matrix);

  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << ' ';
  }

  return 1;
}