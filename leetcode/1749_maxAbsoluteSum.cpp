#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxAbsoluteSum(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return 0;

    int maxEnds = nums[0];
    int minEnds = nums[0];
    int maxi = nums[0];
    int mini = nums[0];

    for (int i = 1; i < n; i++) {
      maxEnds = max(nums[i], maxEnds + nums[i]);
      minEnds = min(nums[i], minEnds + nums[i]);

      maxi = max(maxi, maxEnds);
      mini = min(mini, minEnds);
    }
    return max(abs(maxi), abs(mini));
  }
};

int main() {
  Solution obj;
  vector<int> nums = {2, -5, 1, -4, 3, -2};
  int res = obj.maxAbsoluteSum(nums);

  cout << res;

  return 0;
}
