#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool twoSum(vector<int>& nums, int k) {
    int n = nums.size();
    // edge case
    if (n <= 1) return false;
    sort(nums.begin(), nums.end());

    int i = 0, j = n - 1;
    while (i < j) {
      int sum = nums[i] + nums[j];
      if (sum < k) {
        i++;
      } else if (sum > k) {
        j--;
      } else {
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {4, 7, 1, 9};
  int k = 8; 
  cout << obj.twoSum(nums, k);

  return 0;
}
