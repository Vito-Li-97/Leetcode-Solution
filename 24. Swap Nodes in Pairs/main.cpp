
#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {  // 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
                                         // 不修改节点内部的值，只能进行节点交换。
    if (head == nullptr) {
      return head;
    }
    if (head->next == nullptr) {
      return head;
    }

    ListNode *dummy, *cur, *temp;
    dummy = new ListNode(0, head);
    cur = dummy;
    while (cur->next != nullptr && cur->next->next != nullptr) {
      temp = head->next->next;

      cur->next = head->next;
      head->next->next = head;
      head->next = temp;

      cur = head;
      head = temp;
    }
    return dummy->next;
  }
};

ListNode* createList(vector<int> arr) {  // 根据vector生成一个List
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
  vector<int> inputs = {1, 2, 3, 4};
  ListNode* list_input = createList(inputs);

  Solution solve;
  ListNode* result = solve.swapPairs(list_input);

  ListNode* cur = result;
  while (cur != nullptr) {
    cout << cur->val << endl;
    cur = cur->next;
  }

  return 0;
}