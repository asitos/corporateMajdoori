#include <iostream>
using namespace std;

class Solution {
public:
  void printOneToN(int n) {
    // void printOneToN(int curr, int n) {
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
    // if (curr > n) {
    //   cout << "\n";
    //   return;
    // }
    // cout << curr << " ";
    //
    // printOneToN(curr + 1, n);
    // tnp appraoch
    if (n == 0)
      return;

    // order matters here, we call our funcion before print statement
    // call before print -> 1 to N
    // print before call -> N to 1

    printOneToN(n - 1);
    cout << n << " ";
  }
};

int main() {
  Solution obj;
  int n = 5;

  // obj.printOneToN(1, n);
  obj.printOneToN(n);
  return 0;
}
