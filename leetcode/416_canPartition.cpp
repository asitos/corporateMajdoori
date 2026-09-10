#include <bits/stdc++.h>
using namespace std;

// global dp array
int dp[201][20001];

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int n = nums.size();

    // check if sum is even, and partitioning is possible
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
      totalSum += nums[i];
    }

    if (totalSum % 2 != 0) {
      return false;
    } else {
      return solve(nums, totalSum / 2,
                   n); // check only for 1 possible partition
    }
  }

  // recursive code
  // bool solve(vector<int> &nums, int sum, int n) {
  //   // base condition
  //   if (n == 0) {
  //     return false;
  //   }
  //
  //   if (sum == 0) {
  //     return true;
  //   }
  //
  //   // choice
  //
  //   if (nums[n - 1] <= sum) {
  //     return (solve(nums, sum - nums[n - 1], n - 1) || solve(nums, sum, n -
  //     1));
  //   } else {
  //     return solve(nums, sum, n - 1);
  //   }
  // }
  //
  // memoized approach
  // bool solve(vector<int> &nums, int sum, int n) {
  //   // initialise dp
  //   memset(dp, -1, sizeof(dp));
  //
  //   // base condition
  //   if (sum == 0) {
  //     return true;
  //   }
  //
  //   if (n == 0) {
  //     return false;
  //   }
  //
  //   if (dp[n][sum] != -1) {
  //     return dp[n][sum];
  //   }
  //
  //   // choice
  //
  //   if (nums[n - 1] <= sum) {
  //     return dp[n][sum] = (solve(nums, sum - nums[n - 1], n - 1) ||
  //                          solve(nums, sum, n - 1));
  //   } else {
  //     return dp[n][sum] = solve(nums, sum, n - 1);
  //   }
  // }
  //
  // tabulation approach
  bool solve(vector<int> &nums, int sum, int n) {
    // initialise table
    for (int i = 0; i <= n; i++) {
      dp[i][0] = true;
    }

    for (int j = 1; j <= sum; j++) {
      dp[0][j] = false;
    }

    // choice
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= sum; j++) {
        if (nums[i - 1] <= j) {
          dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[n][sum];
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 5, 11, 5};
  cout << obj.canPartition(nums);

  return 0;
}
