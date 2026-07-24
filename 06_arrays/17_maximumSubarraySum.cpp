#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long maximumSubarraySum(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    long long maxi = LLONG_MIN;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
      sum += nums[i];

      if (sum > maxi) {
        maxi = sum;
      }

      if (sum < 0) {
        sum = 0;
      }
    }

    return maxi;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  long long res = obj.maximumSubarraySum(nums);

  cout << res;

  return 0;
}
