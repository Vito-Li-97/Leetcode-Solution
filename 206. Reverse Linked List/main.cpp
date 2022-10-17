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

class Solution {  // 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 public:
  ListNode* reverseList(ListNode* head) {  // 双指针法
    ListNode* cur = head;
    ListNode* pre = nullptr;
    ListNode* temp = nullptr;
    while (cur != nullptr) {  // temp存cur的next，cur的next指向pre，pre移到cur，cur移到temp
      temp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = temp;
    }
    return pre;
  };

  ListNode* reverse_1(ListNode* pre, ListNode* cur) {  // 递归，从前往后翻转指针指向
    if (cur == nullptr) {
      return pre;
    }
    ListNode* temp = cur->next;
    cur->next = pre;
    return reverse_1(cur, temp);  // 用递归让pre和cur前进
  };
  ListNode* reverseList_1(ListNode* head) {
    return reverse_1(nullptr, head);
  };

  ListNode* reverseList_2(ListNode* head) {  // 递归，从后往前翻转指针指向
    if (head == nullptr) {                   // 边缘条件判断
      return head;
    }
    if (head->next == nullptr) {
      return head;
    }
    ListNode* last = reverseList_2(head->next);  // 递归到入参（head->next）为最后一个节点
                                                 // 然后 return （head->next）
    head->next->next = head;                     // 让入参 head 的next的next指向head，即加上反向指针
    head->next = nullptr;                        // 去除正向指针
    return last;
  };
};

int main() {
  vector<int> inputs = {1, 2, 3, 4, 5};
  ListNode* list_input = createList(inputs);

  Solution solve;
  ListNode* result = solve.reverseList_2(list_input);

  return 0;
}