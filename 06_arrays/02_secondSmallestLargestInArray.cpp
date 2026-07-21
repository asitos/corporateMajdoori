#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> secondSmallestLargestInArray(vector<int>& nums) {
    if (nums.size() < 2) return {-1, -1};

    int min = INT_MAX, secMin = INT_MAX;
    int max = INT_MIN, secMax = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < min) {
        secMin = min;
        min = nums[i];
      } else if (nums[i] < secMin && nums[i] != min) {
        secMin = nums[i];
      }

      if (nums[i] > max) {
        secMax = max;
        max = nums[i];
      } else if (nums[i] > secMax && nums[i] != max) {
        secMax = nums[i];
      }
    }

    if (secMin == INT_MAX || secMax == INT_MIN) return {-1, -1};

    return {secMin, secMax};
  }
};

int main() {
  Solution obj;
  vector<int> nums = {5, 4, 3, 2, 1};
  vector<int> res = obj.secondSmallestLargestInArray(nums);

  for (auto i : res) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
