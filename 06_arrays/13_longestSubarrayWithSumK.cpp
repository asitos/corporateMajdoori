#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestSubarrayWithSumK(vector<int>& nums, int k) {
    int n = nums.size();
    // edge case
    if (n < 1) return 0;

    int res = 0;
    int windowSum = 0;
    int i = 0;

    for (int j = 0; j < n; j++) {
      windowSum += nums[j];
      while (windowSum > k && i <= j) {
        windowSum -= nums[i];
        i++;
      }

      if (windowSum == k) {
        res = max(res, j - i + 1);
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
