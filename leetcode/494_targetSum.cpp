#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findTargetSumWays, (vector<int> & nums, int target) {

    return memoizedSolve(nums, 0, target, 0);
  }

  // recursive func (huge runtime)
  // int recurFunc(vector<int> &nums, int idx, int target, int curr) {
  //   int n = nums.size();
  //
  //   // base case
  //   if (idx >= n) {
  //     if (curr == target)
  //       return 1;
  //     return 0;
  //   }
  //
  //   // take
  //   int take = recurFunc(nums, idx + 1, target, curr + nums[idx]);
  //
  //   // not take
  //   int notTake = recurFunc(nums, idx + 1, target, curr - nums[idx]);
  //
  //   return (take + notTake);
  // }
  //
  // memoization approach
};

int main() {
  Solution obj;
  vector<int> nums = {1, 1, 1, 1, 1};
  int res = obj.findTargetSumWays(nums, 3);

  cout << res;

  return 0;
}
