
#include <iostream>

class MyLinkedList {  // doubly linked list

 public:
  struct ListNode {  // denfine linkedlist
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode* next_node, ListNode* prev_node)
        : val(x), next(next_node), prev(prev_node) {}
  };

  int _size;
  ListNode* _head;  // dummy node
  ListNode* _trailer;

  MyLinkedList() {  // 列表包含的初始化变量，在创建列表对象时统一调用
    _size = 0;
    _head = new ListNode(0);
    _trailer = new ListNode(0);
  }

  int get(int index) {  // 获取链表中第 index 个节点的值。如果索引无效，则返回-1。
    ListNode* p = new ListNode(-1);
    p->next = _head;
    if (index > 0 && index <= _size) {
      while (index--) {  // 先判断，再index减一，循环index次，p->next为第 index 个节点
        p = p->next;
      }
    }
    return p->next->val;
  }

  void addAtHead(int val) {  // 在链表的第一个元素之前添加一个值为 val 的节点。
                             // 插入后，新节点将成为链表的第一个节点。
    addAtIndex(0, val);
  }

  void addAtTail(int val) {  // 将值为 val 的节点追加到链表的最后一个元素。
    addAtIndex(_size, val);
  }

  void addAtIndex(int index, int val) {  // 在链表中的第 index 个节点之前添加值为 val 的节点。
                                         // 如果 index 等于链表的长度，则该节点将附加到链表的末尾。
                                         // 如果 index 大于链表长度，则不会插入节点。
                                         // 如果 index 小于0，则在头部插入节点。
    if (index > _size) {
      return;
    }

    if (index < 0) {
      index = 0;
    }

    ListNode* p = new ListNode(val);
    ListNode* cur = _head;
    while (index--) {  // cur位移index次， cur->next = index node
      cur = cur->next;
    }
    p->next = cur->next;  // p to index node
    cur->next = p;        // cur to p
    _size++;
  }

  void deleteAtIndex(int index) {  // 如果索引 index 有效，则删除链表中的第 index 个节点。
    if (index >= _size || index < 0) {
      return;
    }

    ListNode* cur = _head;
    while (index--) {  // cur位移index次，达到第index-1个节点处
      cur = cur->next;
    }
    cur->next = cur->next->next;
    _size--;
  }

  void printLinkedList() {  // 打印链表
    ListNode* cur = _head;
    std::cout << "LinkedList ";
    while (cur->next != nullptr) {  // before cur->next is nullptr
      std::cout << cur->next->val << " ";
      cur = cur->next;
    }
    std::cout << std::endl;
  }
};