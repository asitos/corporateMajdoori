#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int jump(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n + 1, -1);

    return solve(nums, 0, n, dp);
  }

  int solve(vector<int> &nums, int idx, int n, vector<int> &dp) {
    // base case
    if (idx >= n - 1) {
      return 0;
    }

    // dp check
    if (dp[idx] != -1) {
      return dp[idx];
    }

    // choice loop
    int minJumps = 10001;

    for (int jump = 1; jump <= nums[idx]; jump++) {
      int currPathCost = 1 + solve(nums, idx + jump, n, dp);
      minJumps = min(minJumps, currPathCost);
    }

    return dp[idx] = minJumps;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {2, 3, 1, 1, 4};
  int res = obj.jump(nums);

  cout << res;

  return 0;
}
