#include <bits/stdc++.h>
using namespace std;

// @leet start
class Solution {
public:
  int count(vector<int> &coins, int sum) {
    int n = coins.size();

    return solve(coins, sum, n);
    // return res;
  }

  int solve(vector<int> &coins, int sum, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    // table initialisation
    for (int i = 0; i <= n; i++) {
      dp[i][0] = 1;
    }

    for (int j = 1; j <= sum; j++) {
      dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= sum; j++) {
        if (coins[i - 1] <= j) {
          dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[n][sum];
  }
};
// @leet end

int main() {
  Solution obj;
  vector<int> nums = {2, 5, 3, 6};
  int sum = 10;
  int res = obj.count(nums, sum);

  cout << res;

  return 0;
}
