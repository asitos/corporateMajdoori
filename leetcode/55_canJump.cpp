#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // bool canJump(vector<int> &nums) {
  //   int n = nums.size();
  //
  //   vector<int> dp(n + 1, -1);
  //
  //   return solve(nums, 0, n, dp);
  // }
  //
  // bool solve(vector<int> &nums, int idx, int n, vector<int>& dp) {
  //
  //   // base case
  //   if (idx >= n - 1) {
  //     return true;
  //   }
  //
  //   // dp check
  //   if (dp[nums[idx]] != -1) {
  //     return dp[nums[idx]];
  //   }
  //
  //
  //   // choice loop
  //   for (int jump = 1; jump <= nums[idx]; jump++) {
  //     if (solve(nums, idx + jump, n, dp)) {
  //       return true;
  //     }
  //   }
  //
  //   return false;
  // }
  //
  // brute force approach
  bool canJump(vector<int> &nums) {
    int n = nums.size();

    int ft = 0;
    for (int i = 0; i < n; i++) {
      if (i > ft) {
        return false;
      }

      ft = max(ft, i + nums[i]);
      if (ft >= n - 1) {
        return true;
      }
    }

    return false;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {2, 3, 1, 1, 4};
  bool res = obj.canJump(nums);

  cout << res;

  return 0;
}
