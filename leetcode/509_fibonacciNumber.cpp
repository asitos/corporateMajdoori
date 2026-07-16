#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int fib(int n) {
    // base case
    if (n <= 1) {
      return n;
    }
    
    int a = fib(n - 1);
    int b = fib(n - 2);

    return a + b;
  }
};

int main() {
  Solution obj;
  int n = 5;
  cout << obj.fib(n);

  return 0;
}
