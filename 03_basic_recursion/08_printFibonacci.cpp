#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int printFibonacci(int n) {
    // base case 
    if (n <= 1) {
      return n;
    }

    int a = printFibonacci(n - 1);
    int b = printFibonacci(n - 2);
 
    return b + a;

  }
};

int main() {
  Solution obj;
  int n = 5;
  cout << obj.printFibonacci(n) << "\n";

  return 0;
}

