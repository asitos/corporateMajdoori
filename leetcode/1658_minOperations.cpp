#include <bits/stdc++.h>
using namespace std;

// @leet start
class Solution {
public:
  int minOperations(vector<int> &nums, int x) {
    int n = nums.size();
    //   weird approach
    //   int i = 0, j = n - 1;
    //   int choice = INT_MIN;
    //   int ops = 0;
    //
    //   // edge case
    //   if (n <= 2)
    //     return -1;
    //
    //   while (x != 0 && i < j) {
    //     if (nums[i] <= x || nums[j] <= x) {
    //       choice = (max(nums[i], nums[j]) <= x) ? max(nums[i], nums[j])
    //                                             : min(nums[i], nums[j]);
    //       x = x - choice;
    //       ops++;
    //       if (choice == nums[i]) {
    //         i++;
    //       } else {
    //         j--;
    //       }
    //     } else {
    //       return -1;
    //     }
    //   }
    //
    //   return ops;
    // }
    // optimal sliding window O(n)
    long long totalSum = 0;
    for (int num : nums) {
      totalSum += num;
    }
    long long target = totalSum - x;

    if (target == 0)
      return n;
    if (target < 0)
      return -1;

    int maxLen = -1;
    long long currSum = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
      currSum += nums[right];
      while (left <= right && currSum > target) {
        currSum -= nums[left];
        left++;
      }
      if (currSum == target) {
        maxLen = max(maxLen, right - left + 1);
      }
    }
    return (maxLen == -1) ? -1 : (n - maxLen);
  }
};
// @leet end

int main() {
  Solution obj;
  vector<int> nums = {1, 1, 4, 2, 3};
  int x = 5;
  int res = obj.minOperations(nums, x);

  cout << res;

  return 0;
}
