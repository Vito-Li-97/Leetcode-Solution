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

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (slow == fast) {       // 相遇的时候，slow的路程等于圈周长
        ListNode *cur1 = head;  // 新指针从head出发，与slow相遇即为入口处
        while (cur1 != slow) {
          cur1 = cur1->next;
          slow = slow->next;
        }
        return cur1;
      }
    }
    return nullptr;
  }

  ListNode *detectCycle_1(ListNode *head) {  // hash map
    unordered_set<ListNode *> visited;       // 将遍历的节点收录到unordered_set中，
                                             // 新节点与已有的重复时return
    while (head != nullptr) {
      if (visited.count(head)) {  // Searches the container for elements with the value
        return head;
      }
      visited.insert(head);
      head = head->next;
    }
    return nullptr;
  }
};

ListNode *createList(vector<int> arr, int entrance) {  // 生成一个环形List
  int i;
  ListNode *p, *head, *trail, *pre;
  head = new ListNode(0);  // 虚拟头节点，最后去掉
  pre = head;
  trail = nullptr;
  for (i = 0; i < arr.size(); i++) {
    p = new ListNode(arr[i]);  // 建立新节点p
    pre->next = p;             // 将pre代表的节点指向新节点p
    pre = p;                   // pre前进到新节点
    if (i == entrance - 1) {
      trail = p;
    }
  }
  pre->next = trail;
  return head->next;
}

int main() {
  vector<int> inputs = {3, 2, 0, -4};
  ListNode *list_input = createList(inputs, 3);

  Solution solve;
  ListNode *result = solve.detectCycle(list_input);
  cout << result->val << endl;

  return 0;
}
