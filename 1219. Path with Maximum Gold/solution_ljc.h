using namespace std;
#include <functional>
#include <vector>

class Solution {
 public:
  static constexpr int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  int getMaximumGold(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[1].size();
    int ans = 0;

    function<void(int, int, int)> f1 = [&](int x, int y, int gold) {
      // 输入出发点坐标x,y以及进入此区域前的gold
      // 得到所有从这出发的可能性的gold的最大值ans
      gold += grid[x][y];
      ans = max(ans, gold);
      int cache = grid[x][y];
      grid[x][y] = 0;
      for (int k = 0; k < 4; k++) {
        int nx = x + dir[k][0];  //沿着4个方向
        int ny = y + dir[k][1];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0) {
          //不出界且此区域不为0
          f1(nx, ny, gold);
        }
      }
      grid[x][y] = cache;
    };

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] > 0) {
          f1(i, j, 0);
        }
      }
    }

    return ans;
  }
};