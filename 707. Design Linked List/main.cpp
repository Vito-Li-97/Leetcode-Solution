
#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define DLEVEL 2

#if DLEVEL == 1
#include "LinkedList_singly.h"
#elif DLEVEL == 2
#include "LinkedList_doubly.h"
#endif

class Test {  // 读取测试算例的文本，把相应的文本转化为对应的命令，输出测试结果
 private:
  vector<string> splitString(string str, string delimiter1, string delimiter2) {  // 按分隔符分割字符串
    size_t pos1 = 0;
    size_t pos2 = 0;
    vector<string> words{};

    // 去除开头与结尾的符号
    str.erase(0, 1);
    str.erase(str.end() - 1, str.end());

    while ((pos1 = str.find(delimiter1)) != string::npos) {
      // find 返回给定子字符串开始的位置，否则返回 string::npos
      str.erase(0, pos1 + delimiter1.length());  // remove delimiter1 and content before it
      while ((pos2 = str.find(delimiter2)) != string::npos) {
        words.push_back(str.substr(0, pos2));      // 用 substr 访问分隔符之间的部分
        str.erase(0, pos2 + delimiter2.length());  // 用 erase 删除该部分以及分隔符
        break;                                     // erase(a,b) and substr(a,b) means interval [a,b)
      }
    }

    return words;
  }

 public:
  vector<string> str3;
  vector<string> str4;

  int readTestData(int num) {  // 读取test文件进行相应的测试
    string str1;               // 命令名
    string str2;               // 命令参数

    ifstream infile;  // 以读模式打开文件
    infile.open("test_input.dat");

    for (int i = 0; i < num; i++) {
      infile >> str1;
      infile >> str2;
    }
    cout << str1 << endl;
    cout << str2 << endl;
    infile.close();  // 关闭打开的文件

    str3 = splitString(str1, "\"", "\"");  // 得到每项命令以及对应参数
    str4 = splitString(str2, "[", "]");

    cout << endl;
    for (int i = 0; i < str3.size(); i++) {
      cout << setw(15) << str3[i] << setw(15) << str4[i] << endl;
    }

    return 0;
  }

  int testResult() {  // 根据相应的字符串进行相应的命令
    MyLinkedList linkedList = MyLinkedList();

    for (int i = 0; i < str3.size(); i++) {
      if (str3[i] == "MyLinkedList") {
        MyLinkedList linkedList = MyLinkedList();
      } else if (str3[i] == "get") {
        cout << "get " << linkedList.get(stoi(str4[i])) << endl;
      } else if (str3[i] == "addAtHead") {
        linkedList.addAtHead(stoi(str4[i]));
      } else if (str3[i] == "addAtTail") {
        linkedList.addAtTail(stoi(str4[i]));
      } else if (str3[i] == "addAtIndex") {
        string str = str4[i];  // two arguments
        size_t pos = str.find(",");
        int arg1 = stoi(str.substr(0, pos));
        int arg2 = stoi(str.substr(pos + 1));
        linkedList.addAtIndex(arg1, arg2);
      } else if (str3[i] == "deleteAtIndex") {
        linkedList.deleteAtIndex(stoi(str4[i]));
      };

      linkedList.printLinkedList();
    }

    return 0;
  }
};

int main() {
  Test test;
  int num_test = 1;
  test.readTestData(num_test);
  test.testResult();

  return 0;
}
