#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;

// global dp array
// int dp[21][2001];

class Solution {
public:
  // recursive func (huge runtime)
  // int solve(vector<int> &nums, int target_sum, int n) {
  //
  //   // base case
  //   if (n == 0) {
  //     if (target_sum == 0)
  //       return 1;
  //     return 0;
  //   }
  //
  //   // choice
  //   if (nums[n - 1] <= target_sum) {
  //     return solve(nums, target_sum - nums[n - 1], n - 1) +
  //            solve(nums, target_sum, n - 1);
  //   } else {
  //     return solve(nums, target_sum, n - 1);
  //   }
  // }
  //
  // memoization approach
  // int solve(vector<int> &nums, int target_sum, int n) {
  //
  //   // initialise table
  //   memset(dp, -1, sizeof(dp));
  //
  //   // base case
  //   if (n == 0) {
  //     if (target_sum == 0) {
  //       return 1;
  //     } else {
  //       return 0;
  //     }
  //   }
  //
  //   // dp check
  //   if (dp[n][target_sum] != -1) {
  //     return dp[n][target_sum];
  //   }
  //
  //   // memoized choice
  //   if (nums[n - 1] <= target_sum) {
  //     return dp[n][target_sum] = solve(nums, target_sum - nums[n - 1], n - 1)
  //     +
  //                                solve(nums, target_sum, n - 1);
  //   } else {
  //     return dp[n][target_sum] = solve(nums, target_sum, n - 1);
  //   }
  // }
  // tabulation approach
  // int solve(vector<int> &nums, int target_sum, int n) {
  //   // initialise table
  //   dp[0][0] = 1;
  //   for (int j = 1; j < target_sum; j++) {
  //     dp[0][j] = 0;
  //   }
  //
  //   for (int i = 1; i <= n; i++) {
  //     for (int j = 0; j <= target_sum; j++) {
  //       if (nums[i - 1] <= j) {
  //         dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
  //       } else {
  //         dp[i][j] = dp[i - 1][j];
  //       }
  //     }
  //   }
  //
  //   return dp[n][target_sum];
  // }
  // int findTargetSumWays(vector<int> &nums, int target) {
  //   int n = nums.size();
  //
  //   int totalSum = 0;
  //   for (int x : nums) {
  //     totalSum += x;
  //   }
  //
  //   // edge case check
  //   if (totalSum < abs(target) || (totalSum + target) % 2 != 0) {
  //     return 0;
  //   }
  //
  //   int curr = (totalSum + target) / 2;
  //
  //   return solve(nums, curr, n);
  // }
  //
  // 1D space optimised approach
  int findTargetSumWays(vector<int> &nums, int target) {
    int totalSum = 0;
    for (int x : nums) {
      totalSum += x;
    }

    if (totalSum < abs(target) || (totalSum + target) % 2 != 0) {
      return 0;
    }

    int subsetSum = (totalSum + target) / 2;

    vector<int> dp(subsetSum + 1, 0);
    // int dp[subsetSum + 1];
    // memset(dp, 0, sizeof(dp));
    dp[0] = 1; // sum 0 is always possible

    for (int x : nums) {
      for (int j = subsetSum; j >= x; j--) {
        dp[j] = dp[j] + dp[j - x];
      }
    }

    return dp[subsetSum];
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 1, 1, 1, 1};
  int res = obj.findTargetSumWays(nums, 3);

  cout << res;

  return 0;
}
