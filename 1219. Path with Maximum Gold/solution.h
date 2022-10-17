
#include <functional>
#include <vector>

class Solution {
 private:
  // 方向向量，上下左右
  // constexpr 为 编译期常量， const 为"只读"变量
  static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

 public:
  int getMaximumGold(vector<vector<int>>& grid) {
    // 输入黄金地图二维向量，输出可以获得的最大金量
    int m = grid.size(), n = grid[0].size();  // m*n grid
    int ans = 0;                              // maximum gold

    function<void(int, int, int)> dfs = [&](int x, int y, int gold) {
      // 声明一个 function 类型，调用一个 lambda 表达式
      // lambda 隐式捕获列表，引用捕获：该lambda使用的来自所在函数的实体都用引用方式使用
      // 输入 x y gold 得到 从该点出发沿着四个方向探索后的最大gold值 ans
      gold += grid[x][y];
      ans = max(ans, gold);

      // rec记录{x,y}处的金量，并将该处的gold暂时设为0，防止dfs迭代时回到该点
      int rec = grid[x][y];
      grid[x][y] = 0;

      for (int d = 0; d < 4; ++d) {  // 朝4个不同方向走一步后的gold
        int nx = x + dirs[d][0];
        int ny = y + dirs[d][1];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0) {
          // 如果新位置{nx,ny}没有出界，且gold不为0，则继续
          dfs(nx, ny, gold);
        }
      }

      grid[x][y] = rec;  // 遍历完所有从{x,y}出发的可能性后，将{x,y}的gold还原
    };

    for (int i = 0; i < m; ++i) {  // 枚举每个起始点，如果起点gold不为0，则开始
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] != 0) {
          dfs(i, j, 0);
        }
      }
    }

    return ans;
  }
};