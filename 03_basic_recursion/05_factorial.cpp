#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int iterativeFactorial(int n) {
    // iterative Solution 
    int res = 1;

    for (int i = 1; i <= n; i++) {
      res *= i;
    }

    return res;
  }

  int recursiveFactorial(int n) {
    // recursive solution
    if (n <= 1) {
      return 1;
    }

    return n * recursiveFactorial(n - 1);
  }
};

int main() {
  Solution obj;
  int n = 6;
  cout << obj.iterativeFactorial(n) << "\n";
  cout << obj.recursiveFactorial(n);

  return 0;
}
