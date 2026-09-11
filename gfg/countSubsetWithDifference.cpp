#include <bits/stdc++.h>
using namespace std;

int dp[50][50];

class Solution {
public:
  int countPartitions(vector<int> &nums, int diff) {
    int n = nums.size();

    int totalSum = 0;
    for (int x : nums) {
      totalSum += x;
    }

    // edge case check
    if (totalSum < diff || (totalSum + diff) % 2 != 0) {
      return 0;
    }

    int target = (totalSum + diff) / 2;

    return countSubsetWithSum(nums, target, n);
  }

  // 2d tabulation
  // int countSubsetWithSum(vector<int> &nums, int sum, int n) {
  // initialise table
  // vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
  // dp[0][0] = 1; // 0 sum is always possible
  // for (int j = 1; j <= sum; j++) {
  //   dp[0][j] = 0; // 0 elements cannot form any sum > 0
  // }
  //
  // // choice
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 0; j <= sum; j++) {
  //     if (nums[i - 1] <= j) {
  //       dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
  //     } else {
  //       dp[i][j] = dp[i - 1][j];
  //     }
  //   }
  // }
  // return dp[n][sum];
  //
  //}
  //
  // optimal 1d Solution
  //
  int countSubsetWithSum(vector<int> &nums, int sum, int n) {
    int dp[sum + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
      for (int j = sum; j >= nums[i]; j--) {
        dp[j] = dp[j] + dp[j - nums[i]];
      }
    }

    return dp[sum];
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 1, 2, 3};
  int diff = 1;
  int res = obj.countPartitions(nums, diff);

  cout << res;

  return 0;
}
