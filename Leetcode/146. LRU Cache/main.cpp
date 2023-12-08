#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {  // 方法：哈希表 + 双向链表
 private:
  struct Node {  // 双向链表，储存 key, value，头部储存最近使用节点
    int key, value;
    Node* prev;
    Node* next;
    // constructor
    Node() {
      key = 0;
      value = 0;
      prev = NULL;
      next = NULL;
    };
    Node(int _key, int _value) {
      key = _key;
      value = _value;
      prev = NULL;
      next = NULL;
    };
  };
  Node *head, *tail;
  int listSize, capacity;  // 链表的size，与最大容量

  unordered_map<int, Node*> umap;  // 哈希表 <key, &node>

 public:
  LRUCache(int _capacity) {
    capacity = _capacity;
    listSize = 0;
    // 构造头部和尾部哨兵节点
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (umap.count(key) != 0) {
      // 如果 key 存在，通过哈希表定位节点在链表的位置
      // 将其移动到链表的头部（最近被使用的节点），最后返回该节点的值。
      Node* pNode = umap[key];
      moveToHead(pNode);
      return pNode->value;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    // 插入或改变key-value
    if (umap.count(key) != 0) {
      // 如果key存在，则改变链表节点的value，并移到头部
      Node* pNode = umap[key];
      pNode->value = value;
      moveToHead(pNode);
    } else {
      // 如果key不存在，创建新节点加入到链表头部，与哈希表中
      // 如果超出容量，则删除链表尾部节点，以及其在哈希表的信息
      Node* pNode = new Node(key, value);
      insertToHead(pNode);
      listSize++;
      umap[key] = pNode;
      if (listSize > capacity) {
        pNode = tail->prev;
        removeNode(pNode);
        listSize--;
        umap.erase(pNode->key);
      }
    }
  }

  void removeNode(Node* node) {
    // 去除节点
    node->next->prev = node->prev;
    node->prev->next = node->next;
  }

  void insertToHead(Node* node) {
    // 头部哨兵节点后插入节点
    head->next->prev = node;
    node->prev = head;
    node->next = head->next;
    head->next = node;
  }

  void moveToHead(Node* node) {
    // 将节点移动到链表头部
    removeNode(node);
    insertToHead(node);
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  LRUCache* lRUCache = new LRUCache(2);
  lRUCache->put(1, 1);               // 缓存是 {1=1}
  lRUCache->put(2, 2);               // 缓存是 {1=1, 2=2}
  cout << lRUCache->get(1) << endl;  // 返回 1
  lRUCache->put(3, 3);               // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
  cout << lRUCache->get(2) << endl;  // 返回 -1 (未找到)
  lRUCache->put(4, 4);               // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
  cout << lRUCache->get(1) << endl;  // 返回 -1 (未找到)
  cout << lRUCache->get(3) << endl;  // 返回 3
  cout << lRUCache->get(4) << endl;  // 返回 4

  return 0;
}