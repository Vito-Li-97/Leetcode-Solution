
#include <iostream>  // std::cout
#include <vector>    // std::vector
using namespace std;

struct ListNode {
  int val;                                    // the value of the node
  ListNode* next;                             // a pointer to the next node (type is ListNode)
  ListNode() : val(0), next(nullptr) {}       // 无参数时，val=0, next=nullptr
  ListNode(int x) : val(x), next(nullptr) {}  // 输入一个int时 val=x, next=nullptr
  ListNode(int x, ListNode* next_node)
      : val(x), next(next_node) {}  // 输入两种参数时，val=x, next=next_node
};

class Solution {  //将首节点与其他分开考虑
 public:
  ListNode* removeElements(ListNode* head, int val) {
    // 删除头结点
    while (head != nullptr && head->val == val) {
      ListNode* tmp = head;  // tmp指向head的首节点
      head = head->next;     // 将head的首节点设为原首节点的后继节点
      delete tmp;            // 删除原本的首节点
    }

    // 删除非头结点
    ListNode* cur = head;
    while (cur != nullptr && cur->next != nullptr) {
      if (cur->next->val == val) {
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
      } else {
        cur = cur->next;
      }
    }
    return head;
  }
};

class Solution2 {  // 设置一个虚拟头结点
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummyHead = new ListNode(0);  // 设置一个虚拟头结点
    dummyHead->next = head;                 // 将虚拟头结点的next指向head的首节点
    ListNode* cur = dummyHead;
    while (cur->next != nullptr) {  //将cur的next作为判据
      if (cur->next->val == val) {  //如果cur的next的val等于特定值
        ListNode* tmp = cur->next;  //先设一个指针tmp等于cur的next，将cur的next指向next的next
        cur->next = cur->next->next;
        delete tmp;
      } else {
        cur = cur->next;  // cur指向原cur的后继节点
      }
    }
    head = dummyHead->next;
    delete dummyHead;  // 删除虚拟头节点
    return head;
  }
};

class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    if (head == nullptr) {  //如果head为空，返回head
      return head;
    }
    head->next = removeElements(head->next, val);
    //对 head->next 节点使用函数检定，将返回值赋给 head->next
    return head->val == val ? head->next : head;
    //对 head 的节点进行检定
    //若 head->val 为特定值，返回 head->next，相当于跳过了head
    //若 head->val 不为特定值，返回 head，相当于不对head做变化
  }
};

int main() {
  vector<int> arr = {1, 2, 6, 3, 4, 5, 6};
  ListNode* head = nullptr;  // 创建一个名为head的指针（ListNode类型）
  // 指向nullptr作为尾结点

  for (int i = 0; i < arr.size(); i++) {
    head = new ListNode(arr[i], head);
    // 用new方法，创建一个ListNode类型的struct（暂称为A），
    // 并使用其构造函数，将 arr[i] 付给A.val，将 head 赋给A.next
    // 再用 head 指向这个A，代替了A
    // 从而 head->val = arr[i], head->next = 原head
  }

  for (ListNode* ptr = head; ptr != nullptr; ptr = ptr->next) {
    cout << ptr->val << " ";
  }
  cout << endl;

  Solution s1;
  int val = 6;
  head = s1.removeElements(head, val);

  for (ListNode* ptr = head; ptr != nullptr; ptr = ptr->next) {
    cout << ptr->val << " ";
  }

  return 0;
}