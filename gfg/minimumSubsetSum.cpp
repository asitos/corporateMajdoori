#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumSubsetSum(vector<int> &nums) {
    int range = 0;
    for (int x : nums) {
      range += x;
    }

    int target = range / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true; // sum 0 is always possible

    for (int num : nums) {
      for (int j = target; j >= num; j--) {
        dp[j] = dp[j] || dp[j - num];
      }
    }

    for (int s1 = target; s1 >= 0; s1--) {
      if (dp[s1]) {
        return range - 2 * s1; // first true value from target down to 0 is ans
      }
    }
    return 0;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 2, 7};

  cout << obj.minimumSubsetSum(nums);

  return 0;
}
