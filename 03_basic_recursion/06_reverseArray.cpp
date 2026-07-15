#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> reverseArray(vector<int>& arr) {
    // brute force approach O(n)
    // int n = arr.size();
    // vector<int> res(n);
    //
    // for (int i = 0; i < n; i++) {
    //   res[i] = arr[n - 1 - i];
    // }
    //
    // return res;
    //
    // better approach using two pointers in place using O(1) space
    // edge case 
    if (arr.empty()) {
      return arr;
    }

    int i = 0;
    int j = arr.size() - 1;

    while (i < j) {
      swap(arr[i], arr[j]);
      i++;
      j--;
    }

    return arr;
  }
  void reverseArrayLibrary(vector<int>& arr) {

    reverse(arr.begin(), arr.end());
  }
};

int main() {
  Solution obj;
  // int n = 5;
  vector<int> arr = {1, 2, 3, 4, 5};
  // vector<int> res = obj.reverseArray(arr);
  obj.reverseArrayLibrary(arr);

  cout << "Reversed Array: ";
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
