#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestSubarrayWithSumK(vector<int>& nums, int k) {
    int n = nums.size();
    // edge case
    if (n == 0) return 0;

    int currSum = 0, res = 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
      currSum += nums[i];
      if (currSum == k) {
        res = i + 1;
      }

      if (mp.find(currSum) != mp.end()) {
        res = max(res, i - mp[currSum]);
      } else {
        mp[currSum] = i;
      }
    }

    return res;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {10, 5, 2, 7, 1, 9};
  int k = 15;
  int res = obj.longestSubarrayWithSumK(nums, k);

  cout << res;

  return 0;
}
