
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {  // 请你仅使用两个栈实现先入先出队列。
 private:
  stack<int> stackIn;
  stack<int> stackOut;

 public:
  MyQueue() {
  }

  void push(int x) {  // 将元素 x 推到队列的末尾
    stackIn.push(x);  // 放入入栈
  }

  int peek() {                      // 返回队列开头的元素
    if (stackOut.size() == 0) {     // top 在进栈底或出栈顶。出栈如果为空，队列top元素在入栈底
      while (stackIn.size() > 0) {  // 将进栈全导入出栈。然后入栈为空，top在进栈顶
        stackOut.push(stackIn.top());
        stackIn.pop();
      }
    }
    return stackOut.top();  // 如果出栈不为空，则top在出栈顶
  }

  int pop() {  // 从队列的开头移除并返回元素
    int temp = peek();
    stackOut.pop();
    return temp;
  }

  bool empty() {  // 如果队列为空，返回 true ；否则，返回 false
                  // 如果进栈和出栈都为空的话，说明模拟的队列为空了。
    return stackIn.empty() && stackOut.empty();
  }
};

class MyQueue_1 {  // 普通方法
 private:
  stack<int> stackIn;
  stack<int> stackOut;

 public:
  MyQueue_1() {
  }

  void push(int x) {  // 将元素 x 推到队列的末尾
    while (!stackIn.empty()) {
      stackOut.push(stackIn.top());
      stackIn.pop();
    }
    stackIn.push(x);
    while (!stackOut.empty()) {
      stackIn.push(stackOut.top());
      stackOut.pop();
    }
  }

  int peek() {  // 返回队列开头的元素
    return stackIn.top();
  }

  int pop() {  // 从队列的开头移除并返回元素
    int temp = peek();
    stackIn.pop();
    return temp;
  }

  bool empty() {  // 如果队列为空，返回 true ；否则，返回 false
    return stackIn.empty();
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
  MyQueue_1 myQueue;
  myQueue.push(7);  // queue is: [1]
  myQueue.push(8);  // queue is: [1, 2] (leftmost is front of the queue)
  myQueue.peek();   // return 1
  myQueue.pop();    // return 1, queue is [2]
  myQueue.empty();  // return false

  return 0;
}