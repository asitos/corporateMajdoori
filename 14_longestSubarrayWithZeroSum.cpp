#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int longestSubarrayWithZeroSum(vector<int>& nums) {
    int n = nums.size();

    // edge case
    if (n == 0) return 0;

    int res = 0;
    int currSum = 0;
     
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
      currSum += nums[i];

      if (currSum == 0) {
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
  vector<int> nums = {9, -3, 3, -1, 6, -5};
  int res = obj.longestSubarrayWithZeroSum(nums);

  cout << res;

  return 0;
}
