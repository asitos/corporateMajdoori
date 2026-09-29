#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int printFibonacci(int n) {
    // base case
    if (n <= 1) {
      return n;
    }

    // dp table initialisation
    int dp[n + 1];
    memset(dp, -1, sizeof(dp));

    if (dp[n] != -1) {
      return dp[n];
    }

    return dp[n] = printFibonacci(n - 1) + printFibonacci(n - 2);
  }
};

int main() {
  Solution obj;
  int n = 5;
  cout << obj.printFibonacci(n) << "\n";

  return 0;
}
