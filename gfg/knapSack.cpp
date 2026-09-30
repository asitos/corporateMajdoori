#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

// @leet start
class Solution {
public:
  int knapSack(vector<int> &val, vector<int> &wt, int capacity) {
    // test
    int n = val.size();
    // memset(dp, -1, sizeof(dp));
    return solve(val, wt, capacity, n);
  }
  // memoized approach
  // int solve(vector<int> &val, vector<int> &wt, int capacity, int n) {
  //   // base condition
  //   if (n == 0 || capacity == 0) {
  //     return 0;
  //   }
  //
  //   // dp check
  //   if (dp[n][capacity] != -1) {
  //     return dp[n][capacity];
  //   }
  //
  //   // choice
  //   if (wt[n - 1] <= capacity) {
  //     return dp[n][capacity] =
  //                max(solve(val, wt, capacity, n - 1),
  //                    val[n - 1] + solve(val, wt, capacity - wt[n - 1], n));
  //   } else {
  //     return dp[n][capacity] = solve(val, wt, capacity, n - 1);
  //   }
  // }
  // tabulation approach
  // int solve(vector<int> &val, vector<int> &wt, int w, int n) {
  //   // table initialisation
  //   vector<vector<int>> dp(n + 1, vector<int>(w + 1));
  //
  //   for (int i = 0; i <= n; i++) {
  //     for (int j = 0; j <= w; j++) {
  //       if (i == 0 || j == 0) {
  //         dp[i][j] = 0;
  //       } else { // choice
  //         int pick = 0;
  //         if (wt[i - 1] <= j) {
  //           pick = val[i - 1] + dp[i][j - wt[i - 1]];
  //         }
  //         int notPick = dp[i - 1][j];
  //         dp[i][j] = max(pick, notPick);
  //       }
  //     }
  //   }
  //
  //   return dp[n][w];
  // }
  // 1D space optimised tabulation
  int solve(vector<int> &val, vector<int> &wt, int w, int n) {
    vector<int> dp(w + 1, 0);
    for (int i = 0; i < n; i++) {
      int currWt = wt[i];
      int currVal = val[i];
      // unbounded knapsack needs us to go left to right, upwards
      // unlike 0/1 knapsack, which goes right to left, downwards
      for (int j = currWt; j <= w; j++) {
        dp[j] = max(dp[j], currVal + dp[j - currWt]);
      }
    }
    return dp[w];
  }
};

// @leet end

int main() {
  Solution obj;
  vector<int> val = {10, 40, 50, 70};
  vector<int> wt = {1, 3, 4, 5};
  int capacity = 8;
  int res = obj.knapSack(val, wt, capacity);

  cout << res;

  return 0;
}
