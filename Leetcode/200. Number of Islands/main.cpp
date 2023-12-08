#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
  // 方法：深度优先算法，遍历过的陆地打上标记
 public:
  int inArea(vector<vector<char>>& grid, int i, int j) {
    // 判断格点是否在有效区域内
    if (i < 0 || i > grid.size() - 1 || j < 0 || j > grid[0].size() - 1) {
      return -1;
    } else {
      return 1;
    }
  }

  int islandDFS(vector<vector<char>>& grid, int i, int j) {
    // 递归判断grid[i][j]是否为陆地
    if (inArea(grid, i, j) == -1) {
      // 如果不在有效范围内，返回
      return 0;
    }

    switch (grid[i][j]) {
      case '0':  // 如果为海洋，返回
        return 0;
      case '1':  // 如果为未遍历的陆地，遍历后标记为2，避免重复遍历
        grid[i][j] = '2';
        break;
      case '2':  // 如果为已遍历的陆地，返回
        return 0;
    }

    islandDFS(grid, i - 1, j);
    islandDFS(grid, i + 1, j);
    islandDFS(grid, i, j - 1);
    islandDFS(grid, i, j + 1);

    return 1;
  };

  int numIslands(vector<vector<char>>& grid) {
    // 判断岛屿个数
    int res = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        res += islandDFS(grid, i, j);
      }
    }
    return res;
  }
};

class Solution_1 {
  // 方法：深度优先算法，遍历过的陆地变为0
 public:
  void dfs(vector<vector<char>>& grid, int i, int j) {
    grid[i][j] = '0';

    if (i > 0 && grid[i - 1][j] == '1') {
      dfs(grid, i - 1, j);
    }
    if (i < grid.size() - 1 && grid[i + 1][j] == '1') {
      dfs(grid, i + 1, j);
    }
    if (j > 0 && grid[i][j - 1] == '1') {
      dfs(grid, i, j - 1);
    }
    if (j < grid[0].size() - 1 && grid[i][j + 1] == '1') {
      dfs(grid, i, j + 1);
    }

    return;
  }

  int numIslands(vector<vector<char>>& grid) {
    // 判断陆地个数
    int res = 0;
    int w = grid.size();
    if (w == 0) {
      return res;
    }
    int l = grid[0].size();

    for (int i = 0; i < w; i++) {
      for (int j = 0; j < l; j++) {
        if (grid[i][j] == '1') {
          res++;
          dfs(grid, i, j);
        }
      }
    }

    return res;
  }
};

class Solution_2 {
  // 广度优先搜索，使用队列来记录子节点
 public:
  int numIslands(vector<vector<char>>& grid) {
    int res = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1') {
          res++;
          bfs(grid, i, j);
        }
      }
    }
    return res;
  }

  void bfs(vector<vector<char>>& grid, int i, int j) {
    // 递归检查节点的子节点
    queue<vector<int>> q;  // 记录节点
    q.push({i, j});
    grid[i][j] = '2';  // 标识为遍历过的陆地

    while (!q.empty()) {
      vector<int> cache = q.front();
      i = cache[0];
      j = cache[1];
      q.pop();
      if (i > 0 && grid[i - 1][j] == '1') {
        q.push({i - 1, j});
        grid[i - 1][j] = '2';
      }
      if (i < grid.size() - 1 && grid[i + 1][j] == '1') {
        q.push({i + 1, j});
        grid[i + 1][j] = '2';
      }
      if (j > 0 && grid[i][j - 1] == '1') {
        q.push({i, j - 1});
        grid[i][j - 1] = '2';
      }
      if (j < grid[0].size() - 1 && grid[i][j + 1] == '1') {
        q.push({i, j + 1});
        grid[i][j + 1] = '2';
      }
    }
    return;
  }
};

int main() {
  vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                               {'1', '1', '0', '1', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '0', '0', '0'}};

  Solution_2 solve;
  auto result = solve.numIslands(grid);
  cout << result << endl;

  return 0;
}