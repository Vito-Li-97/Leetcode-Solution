
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if (matrix.empty()) {
      return res;
    }
    int m = matrix.size(), n = matrix[0].size();
    int num = m * n;
    int xl = 0, xm = m - 1, yl = 0, ym = n - 1;

    while (num > 0) {
      for (int i = yl; i <= ym && num > 0; i++) {
        res.push_back(matrix[xl][i]);
        num--;
      }
      xl++;
      for (int i = xl; i <= xm && num > 0; i++) {
        res.push_back(matrix[i][ym]);
        num--;
      }
      ym--;
      for (int i = ym; i >= yl && num > 0; i--) {
        res.push_back(matrix[xm][i]);
        num--;
      }
      xm--;
      for (int i = xm; i >= xl && num > 0; i--) {
        res.push_back(matrix[i][yl]);
        num--;
      }
      yl++;
    }
    return res;
  }
};

int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> matrix1 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  vector<vector<int>> matrix2;

  Solution n1;
  vector<int> vec = n1.spiralOrder(matrix2);

  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << ' ';
  }

  return 1;
}