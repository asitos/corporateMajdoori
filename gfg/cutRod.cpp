#include <bits/stdc++.h>
using namespace std;

// int dp[1001][1001];
// @leet start
class Solution {
public:
  int cutRod(vector<int> &price) {
    int n = price.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
      int pieceLen = i;
      int pieceVal = price[i - 1];

      for (int j = 1; j <= n; j++) {
        if (pieceLen <= j) {
          int pick = pieceVal + dp[i][j - pieceLen];
          int notPick = dp[i - 1][j];
          dp[i][j] = max(pick, notPick);
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[n][n];
    //   // memset(dp, -1, sizeof(dp));
    //   return solve(price, n);
    // }
    //
    // int solve(vector<int> &price, int N) {
    //   // table initialisation
    //   vector<int> dp(N + 1, 0);
    //   for (int i = 0; i < N; i++) {
    //     int currWt = price[i];
    //     int currVal = val[i];
    //     // unbounded knapsack needs us to go left to right, upwards
    //     // unlike 0/1 knapsack, which goes right to left, downwards
    //     for (int j = currWt; j <= w; j++) {
    //       dp[j] = max(dp[j], currVal + dp[j - currWt]);
    //     }
    //   }
    //
    //   return dp[w];
  }
};
// @leet end

int main() {
  Solution obj;
  vector<int> nums = {5, 4, 3, 2, 1};
  int res = obj.cutRod(nums);

  cout << res;

  return 0;
}
