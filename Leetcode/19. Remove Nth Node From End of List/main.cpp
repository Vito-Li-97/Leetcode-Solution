
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

class Solution {  // 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {  // 简陋方法
    int size = 0;
    ListNode* cur = head;
    while (cur != nullptr) {
      size++;
      cur = cur->next;
    }

    if (size < 1) {
      return head;
    }

    ListNode* dummy = new ListNode(0, head);
    cur = dummy;
    for (int i = 0; i < size - n; i++) {  // 正数第size-n+1个，跳size-n次使cur->next为删除元素
      cur = cur->next;
    }
    cur->next = cur->next->next;
    return dummy->next;
  };

  ListNode* removeNthFromEnd_1(ListNode* head, int n) {  // 双指针
    ListNode *slow, *fast;
    ListNode* dummy = new ListNode(0, head);
    fast = dummy;
    for (int i = 0; i < n + 1; i++) {  // fast前进 n+1 次
      fast = fast->next;
    }
    slow = dummy;
    while (fast != nullptr) {  // fast为nullptr，slow->next 为要删除的元素
      fast = fast->next;
      slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
  };

  int cur_2 = 0;
  ListNode* removeNthFromEnd_2(ListNode* head, int n) {  // 最简递归
    if (!head) {
      return nullptr;
    }
    head->next = removeNthFromEnd(head->next, n);
    cur_2++;
    if (n == cur_2) {
      return head->next;
    }
    return head;
  };
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
  vector<int> inputs = {1, 2, 3, 4, 5};
  ListNode* list_input = createList(inputs);
  int num = 2;

  Solution solve;
  ListNode* result = solve.removeNthFromEnd_2(list_input, num);

  ListNode* cur = result;
  while (cur != nullptr) {
    cout << cur->val << endl;
    cur = cur->next;
  }

  return 0;
}