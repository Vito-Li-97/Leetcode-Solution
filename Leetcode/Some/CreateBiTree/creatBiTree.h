
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class creatBiTree {  // 根据string数组，先序递归创建二叉树（空格或null代表空节点）
 private:
  vector<string> splitString(string str, char delimiter1) {  // 分割字符串
    // 去除开头与结尾的符号
    str.erase(0, 1);
    str.erase(str.end() - 1, str.end());

    vector<string> words;
    stringstream sstr(str);
    while (sstr.good()) {
      string substr;
      getline(sstr, substr, delimiter1);
      words.push_back(substr);
    }
    return words;
  }

  void *createBiTree_R(TreeNode *T, vector<string> strs, int count) {  // 递归创建二叉树
    if (count == strs.size()) {
      return;
    }

    if (strs[count] == "null")
      T = nullptr;
    else {
      T = new TreeNode;                         // 产生新的子树
      T->val = stoi(strs[count]);               // 创建节点值
      createBiTree_R(T->left, strs, ++count);   // 递归创建左子树
      createBiTree_R(T->right, strs, ++count);  // 递归创建右子树
    }
  }

 public:
  TreeNode *createBiTree_fromString(string str) {  // 创建二叉树
    vector<string> strs;
    strs = splitString(str, ',');

    TreeNode *T;
    T = createBiTree_R(T, strs, 0);
    return T;
  }
};