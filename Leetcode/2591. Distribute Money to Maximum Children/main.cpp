
#include <vector>
using namespace std;

class Solution {
 public:
  int distMoney(int money, int children) {
    if (money < children) {
      // 满足不了每人1$
      return -1;
    } else if (money > 8 * children) {
      // 给每个人8$后还有剩余
      return children - 1;
    } else if (money - 8 * (children - 1) == 4) {
      //最后那个人（第children个人）不足8$，且等于4$，让最后两个人进行随意分配
      return children - 2;
    } else {
      // 其余情况，每人1$后，剩余money能给几人7$便是8$人数
      return (money - children) / 7;
    }
  }

  int distMoney_1(int money, int children) {
    if (money < children) {
      // 满足不了每人1$
      return -1;
    }

    money -= children;
    int cnt = min(money / 7, children);  // 给尽可能多的人分配7美元

    // 剩余的钱和人
    money -= cnt * 7;
    children -= cnt;

    if ((children == 0 && money > 0) || (children == 1 && money == 3)) {
      // （余人=0且余钱>0）和（余人=1且余钱=3）这两种特殊情况，都要毁掉前一个人的正好8元
      cnt--;
    }

    return cnt;  //（余人=0且余钱=0）（余人=1且余钱!=3）（余人>1）
  }
};