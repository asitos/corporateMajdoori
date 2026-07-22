#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    //edge case
    if (k == 0 || n <= 1) return;

    // brute force
    // vector<int> temp(n);
    //
    // for (int i = 0; i < n; i++) {
    //   temp[(i + k) % n] = nums[i];
    // }
    //
    // nums = temp;
    //
    // optimal
    
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

  obj.rotate(nums, 3);

  for (auto i : nums) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
