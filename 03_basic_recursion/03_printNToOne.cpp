#include <iostream>
using namespace std;

class Solution {
public:
  void printNToOne(int curr) {
    // forward recursion O(n) 
    // if (curr < 1) {
    //   return;
    // }
    //
    // cout << curr << " ";
    // printNToOne(curr - 1);
    //
    // backtracking O(n) 
    if (curr < 1) {
      return;
    }
    printNToOne(curr - 1);
    cout << curr << " ";
  }
};

int main() {
  Solution obj;
  int n = 10;
  obj.printNToOne(n);

  return 0;
}
