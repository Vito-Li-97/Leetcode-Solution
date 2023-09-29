#include <iostream>
#include <vector>
using namespace std;

class LockingTree {  //官方解答
 public:
  LockingTree(vector<int>& parent) {
    int n = parent.size();
    this->parent = parent;
    this->lockNodeUser = vector<int>(n, -1);
    this->children = vector<vector<int>>(n);
    for (int i = 0; i < n; i++) {
      int p = parent[i];
      if (p != -1) {
        children[p].emplace_back(i);
      }
    }
  }

  bool lock(int num, int user) {
    if (lockNodeUser[num] == -1) {
      lockNodeUser[num] = user;
      return true;
    }
    return false;
  }

  bool unlock(int num, int user) {
    if (lockNodeUser[num] == user) {
      lockNodeUser[num] = -1;
      return true;
    }
    return false;
  }

  bool upgrade(int num, int user) {
    bool res = lockNodeUser[num] == -1 &&
               !hasLockedAncestor(num) &&
               checkAndUnlockDescendant(num);
    if (res) {
      lockNodeUser[num] = user;
    }
    return res;
  }

  bool hasLockedAncestor(int num) {
    num = parent[num];
    while (num != -1) {
      if (lockNodeUser[num] != -1) {
        return true;
      }
      num = parent[num];
    }
    return false;
  }

  bool checkAndUnlockDescendant(int num) {
    bool res = lockNodeUser[num] != -1;
    lockNodeUser[num] = -1;
    for (int child : children[num]) {
      res |= checkAndUnlockDescendant(child);
    }
    return res;
  }

 private:
  vector<int> parent;
  vector<int> lockNodeUser;
  vector<vector<int>> children;
};

class LockingTree1 {
 public:
  LockingTree1(vector<int>& parent) {
    int n = parent.size();
    this->parent = parent;
    this->lockNodeUser = vector<int>(n, -1);
    this->children = vector<vector<int>>(n);
    for (int i = 0; i < n; i++) {
      int p = parent[i];  // i节点的父节点为p
      if (p != -1) {
        children[p].emplace_back(i);  //记录第p个节点的子节点i
      }
    }
  }

  bool lock(int num, int user) {
    if (lockNodeUser[num] == -1) {
      lockNodeUser[num] = user;
      return true;
    }
    return false;
  }

  bool unlock(int num, int user) {
    if (lockNodeUser[num] == user) {
      lockNodeUser[num] = -1;
      return true;
    }
    return false;
  }

  bool upgrade(int num, int user) {
    //节点未上锁
    //节点无上锁的祖先节点
    //节点有上锁的子孙节点，然后解锁
    bool res = lockNodeUser[num] == -1 &&
               lockedAncestor(num) &&
               checkAndUnlockDescendant(num);
    if (res) {
      lockNodeUser[num] = user;
    }
    return res;
  }

  bool lockedAncestor(int num) {              //判断节点是否有上锁的祖先节点
    if (parent[num] != -1) {                  //若节点有父
      if (lockNodeUser[parent[num]] != -1) {  //如果父上锁
        return false;
      } else {
        return lockedAncestor(parent[num]);
      }
    }
    return true;  // true代表父节点未上锁
  }

  bool checkAndUnlockDescendant(int num) {  //判断节点是否有上锁的子孙节点，若有就解锁
    bool res = false;
    for (int i : children[num]) {          //遍历节点num的子节点
      res |= lockNodeUser[i] != -1;        //子节点上锁了res变为true
      lockNodeUser[i] = -1;                // unlock
      res |= checkAndUnlockDescendant(i);  //判断子节点的子节点上锁没
    }
    return res;  // false表示没有上锁的子节点
  }

 private:
  vector<int> parent;
  vector<int> lockNodeUser;
  vector<vector<int>> children;
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */

int main() {
  vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};
  LockingTree1 lockingTree = LockingTree1(parent);
  cout << lockingTree.lock(2, 2);     // 返回 true ，因为节点 2 未上锁。
                                      // 节点 2 被用户 2 上锁。
  cout << lockingTree.unlock(2, 3);   // 返回 false ，因为用户 3 无法解锁被用户 2 上锁的节点。
  cout << lockingTree.unlock(2, 2);   // 返回 true ，因为节点 2 之前被用户 2 上锁。
                                      // 节点 2 现在变为未上锁状态。
  cout << lockingTree.lock(4, 5);     // 返回 true ，因为节点 4 未上锁。
                                      // 节点 4 被用户 5 上锁。
  cout << lockingTree.upgrade(0, 1);  // 返回 true ，因为节点 0 未上锁且至少有一个被上锁的子孙节点（节点 4）。
                                      // 节点 0 被用户 1 上锁，节点 4 变为未上锁。
  cout << lockingTree.lock(0, 1);     // 返回 false ，因为节点 0 已经被上锁了。

  return 0;
}
