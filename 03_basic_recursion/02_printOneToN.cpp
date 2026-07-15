#include <iostream>
using namespace std;

class Solution {
public:
  void printOneToN(int curr, int n) {
    // forward recursion O(n)
    // if (curr > n) {
    //   cout << "\n";
    //   return;
    // }
    // cout << curr << " ";
    //
    // printOneToN(curr + 1, n);
    //
    // backtracking O(n) 
    if (curr > n) {
      cout << "\n";
      return;
    }

    printOneToN(curr + 1, n);

    cout << curr << " ";
  }

};

int main() {
  Solution obj;
  int n = 10;

  obj.printOneToN(1, n);
  return 0;
}
