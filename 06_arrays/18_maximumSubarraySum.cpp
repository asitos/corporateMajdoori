#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long printMaximumSubarraySum(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return 0;

    long long maxi = LLONG_MIN;
    long long sum = 0;
    int start = 0;

    int ansStart = -1, ansEnd = -1;

    for (int i = 0; i < n; i++) {

      if (sum == 0) {
        start = i;
      }

      sum += nums[i];

      if (sum > maxi) {
        maxi = sum;
        ansStart = start;
        ansEnd = i;
      }

      if (sum < 0) {
        sum = 0;
      }
    }

    cout << "Subarray with max sum: [ ";
    for (int i = ansStart; i <= ansEnd; i++) {
      cout << nums[i] << " ";
    }
    cout << "]" << endl;

    return maxi;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {2, 3, 5, -2, 7, -4};

  long long res = obj.printMaximumSubarraySum(nums);

  cout << res;

  return 0;
}
