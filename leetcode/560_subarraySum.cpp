#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {

    int n = nums.size();
    // edge case
    if (n == 0) return 0;

    int currSum = 0, res = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;

    for (int i = 0; i < n; i++) {
      currSum += nums[i];
      int rem = currSum - k;

      if (mp.find(rem) != mp.end()) {
        res += mp[rem];
      }

      mp[currSum]++;
    }
    return res;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 2, 3};
  int k = 3;
  int res = obj.subarraySum(nums, k);

  cout << res;

  return 0;
}
