
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> result(k, 0);
    priority_queue<int> use;  // 大根堆

    if (k == 0) {
      return result;
    }

    for (int i = 0; i < k; i++) {
      use.push(arr[i]);
    }

    for (int i = k; i < n; i++) {
      if (use.top() > arr[i]) {
        use.pop();
        use.push(arr[i]);
      }
    }

    for (int i = 0; i < k; i++) {
      result[i] = use.top();
      use.pop();
    }

    return result;
  }

  vector<int> getLeastNumbers_1(vector<int>& arr, int k) {
    multiset<int> use;
    int n = arr.size();
    vector<int> result(k, 0);

    for (int i = 0; i < n; i++) {
      use.insert(arr[i]);
    }

    multiset<int>::iterator iter = use.begin();

    for (int i = 0; i < k; ++i) {
      result[i] = *iter;
      ++iter;
    }

    return result;
  }
};

int main() {
  vector<int> test = {10, 99, 2, 1, 5, 7, 3, 3, 0, 8, 9, 1};
  int k = 5;

  Solution n1;
  vector<int> vec = n1.getLeastNumbers(test, k);

  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << ' ';
  }

  return 1;
}