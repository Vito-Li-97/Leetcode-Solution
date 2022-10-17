
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *cur1 = l1, *cur2 = l2;
    ListNode* head = new ListNode();
    ListNode* cur3 = new ListNode(0, head);

    while (cur1 != nullptr || cur2 != nullptr) {
      int val1 = 0;
      int val2 = 0;

      if (cur1 != nullptr) {
        val1 = cur1->val;
        cur1 = cur1->next;
      }
      if (cur2 != nullptr) {
        val2 = cur2->val;
        cur2 = cur2->next;
      }

      cur3->next->val += val1 + val2;  // cur3->next 为 对应 cur1 or cur2 的位置
      cur3->next->next = new ListNode();
      if (cur3->next->val > 9) {
        cur3->next->val %= 10;
        cur3->next->next->val++;
      }
      cur3 = cur3->next;
    }
    if (cur3->next->val == 0) {
      cur3->next = nullptr;
    }

    return head;
  }
};

ListNode* createList(vector<int> arr) {  // vector to list
  int i;
  ListNode *p, *head, *trail, *pre;
  head = new ListNode(0);  // 虚拟头节点，最后去掉
  pre = head;
  trail = nullptr;
  for (i = 0; i < arr.size(); i++) {
    p = new ListNode(arr[i]);  // 建立新节点p
    pre->next = p;             // 将pre代表的节点指向新节点p
    pre = p;                   // pre前进到新节点
  }
  pre->next = trail;
  return head->next;
}

int main() {
  vector<int> v1 = {2, 4, 9};
  vector<int> v2 = {5, 6, 4, 9};
  ListNode* l1 = createList(v1);
  ListNode* l2 = createList(v2);

  Solution solve;
  ListNode* result = solve.addTwoNumbers(l1, l2);

  return 0;
}