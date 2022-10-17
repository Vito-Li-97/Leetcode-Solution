
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {  // 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
                  // 如果两个链表没有交点，返回 null 。
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {  // 双指针
    ListNode *cur1, *cur2;
    cur1 = headA;
    cur2 = headB;
    int lengthA = 0, lengthB = 0;
    while (cur1 != nullptr) {
      cur1 = cur1->next;
      lengthA++;
    }
    while (cur2 != nullptr) {
      cur2 = cur2->next;
      lengthB++;
    }

    cur1 = headA;
    cur2 = headB;
    if (lengthB > lengthA) {  // A the max
      swap(lengthA, lengthB);
      swap(cur1, cur2);
    }
    for (int i = 0; i < lengthA - lengthB; i++) {  // 两链表尾部对齐，将两个指针拨到同一长度处
      cur1 = cur1->next;
    }

    while (cur1 != nullptr) {
      if (cur1 == cur2) {
        return cur1;
      }
      cur1 = cur1->next;
      cur2 = cur2->next;
    }
    return nullptr;
  }

  ListNode *getIntersectionNode_1(ListNode *headA, ListNode *headB) {
    // hash
    // 首先遍历链表 headA，并将链表 headA 中的每个节点加入哈希集合中。
    // 然后遍历链表 headB，对于遍历到的每个节点，判断该节点是否在哈希集合中
    unordered_set<ListNode *> indices;
    ListNode *cur = headA;
    while (cur != nullptr) {
      indices.insert(cur);
      cur = cur->next;
    }
    cur = headB;
    while (cur != nullptr) {
      if (indices.find(cur) != indices.end()) {
        return cur;
      }
      cur = cur->next;
    }
    return nullptr;
  }
};

int main() {
  // 8
  // [4,1,8,4,5]
  // [5,0,1,8,4,5]
  ListNode *headA, *headB, *headC;
  headC = new ListNode(8);
  headC->next = new ListNode(4);
  headC->next->next = new ListNode(5);

  headA = new ListNode(4);
  headA->next = new ListNode(1);
  headA->next->next = headC;

  headB = new ListNode(5);
  headB->next = new ListNode(0);
  headB->next->next = new ListNode(1);
  headB->next->next->next = headC;

  Solution solve;
  ListNode *result = solve.getIntersectionNode_1(headA, headB);
  cout << result->val << endl;

  return 0;
}