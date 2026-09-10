#include <bits/stdc++.h>
using namespace std;

//  global dp array
// int dp[1001][1001];

class Solution {
public:
  // recursive approach
  // int solve(vector<int> &nums, int sum, int n) {
  //   // base condition check
  //   if (n == 0) {
  //     return sum == 0;
  //   }
  //   // choice
  //   if (nums[n - 1] <= sum) {
  //     return solve(nums, sum - nums[n - 1], n - 1) + solve(nums, sum, n - 1);
  //   } else {
  //     return solve(nums, sum, n - 1);
  //   }
  // }
  //
  // memoization
  // int solve(vector<int> &nums, int sum, int n) {
  // for memoization, initialise everything to -1
  // memset(dp, -1, sizeof(dp));
  //   // base condition check
  //   if (n == 0) {
  //     return sum == 0;
  //   }
  //
  //   // dp check
  //   if (dp[n][sum] != -1) {
  //     return dp[n][sum];
  //   }
  //   // choice
  //   if (nums[n - 1] <= sum) {
  //     return dp[n][sum] = solve(nums, sum - nums[n - 1], n - 1) + solve(nums,
  //     sum, n - 1);
  //   } else {
  //     return dp[n][sum] = solve(nums, sum, n - 1);
  //   }
  // }
  //
  // tabulation
  // int solve(vector<int> &nums, int sum, int n) {
  //   // initialisation (wrong)
  //   // for (int i = 0; i <= n; i++) {
  //   //   dp[i][0] = 1;
  //   // }
  //   // for (int j = 1; j <= sum; j++) {
  //   //   dp[0][j] = 0;
  //   // }
  //   // initialisation (right)
  //   dp[0][0] = 1; // 0 elements form 0 sum as null set
  //   for (int j = 1; j <= sum; j++) {
  //     dp[0][j] = 0; // 0 elements cannot form any sum > 0
  //   }
  //
  //   // choice
  //   for (int i = 1; i <= n; i++) {
  //     for (int j = 0; j <= sum; j++) {
  //       if (nums[i - 1] <= j) {
  //         dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
  //       } else {
  //         dp[i][j] = dp[i - 1][j];
  //       }
  //     }
  //   }
  //
  //   return dp[n][sum];
  // }
  // int perfectSum(vector<int> &nums, int sum) {
  //   int n = nums.size();
  //   return solve(nums, sum, n);
  // }
  //
  // 1D space optimised
  int perfectSum(vector<int> &nums, int sum) {
    int dp[sum + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1; // 0 elements form 0 sum as null set
    for (int i = 0; i < nums.size(); i++) {
      for (int j = sum; j >= nums[i]; j--) {
        dp[j] = dp[j - nums[i]] + dp[j];
      }
    }

    return dp[sum];
  }
};

int main() {
  Solution obj;
  vector<int> nums = {2, 3, 5, 6, 8, 10};
  int sum = 10;

  cout << obj.perfectSum(nums, sum);

  return 0;
}
