#include <bits/stdc++.h>
using namespace std;

// int dp[202][10002];

class Solution {
public:
  // naive recursive solution
  // bool isSubsetSum(vector<int> &nums, int sum) {
  //   int n = nums.size();
  //
  //   return solve(nums, sum, n);
  // }
  //
  // bool solve(vector<int> &nums, int sum, int n) {
  //   // base condition
  //   if (sum == 0) {
  //     return true;
  //   }
  //
  //   if (n == 0) {
  //     return false;
  //   }
  //
  //   // choice
  //   if (nums[n - 1] <= sum) {
  //     return (solve(nums, sum - nums[n - 1], n - 1) || solve(nums, sum, n -
  //     1));
  //   } else {
  //     return solve(nums, sum, n - 1);
  //   }
  // }
  //
  // memoized approach
  // bool isSubsetSum(vector<int> &nums, int sum) {
  //   int n = nums.size();
  //
  //   memset(dp, -1, sizeof(dp));
  //   return solve(nums, sum, n);
  // }
  //
  // bool solve(vector<int> &nums, int sum, int n) {
  //   // base condition
  //   if (sum == 0) {
  //     return true;
  //   }
  //   if (n == 0) {
  //     return false;
  //   }
  //
  //   if (dp[n][sum] != -1) {
  //     return dp[n][sum];
  //   }
  //
  //   // choice
  //   if (nums[n - 1] <= sum) {
  //     return dp[n][sum] = (solve(nums, sum - nums[n - 1], n - 1) ||
  //                          solve(nums, sum, n - 1));
  //   } else {
  //     return dp[n][sum] = solve(nums, sum, n - 1);
  //   }
  // }
  //
  // tabulation approach
  // bool isSubsetSum(vector<int> &nums, int sum) {
  //   int n = nums.size();
  //
  //   // initialise table
  //   for (int i = 0; i <= n; i++) {
  //     dp[i][0] = true;
  //   }
  //   for (int j = 1; j <= sum; j++) {
  //     dp[0][j] = false;
  //   }
  //
  //   for (int i = 1; i <= n; i++) {
  //     for (int j = 1; j <= sum; j++) {
  //       if (nums[i - 1] <= j) {
  //         dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
  //       } else {
  //         dp[i][j] = dp[i - 1][j];
  //       }
  //     }
  //   }
  //
  //   return dp[n][sum];
  // }
  //
  // space optimised 1d dp approach

  bool isSubsetSum(vector<int> &nums, int sum) {
    // vector<bool> dp(sum + 1, false);

    bool dp[sum + 1];
    memset(dp, false, sizeof(dp));

    dp[0] = true;

    for (int num : nums) {
      for (int j = sum; j >= num; --j) {
        dp[j] = dp[j] || dp[j - num];
      }
    }

    return dp[sum];
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 2, 3};
  int sum = 2;

  cout << obj.isSubsetSum(nums, sum);

  return 0;
}
