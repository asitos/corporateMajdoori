#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int n = nums.size();

    // edge case 
    if (n <= 1) return;

    int j = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] != 0) {
        nums[j] = nums[i];
        j++;
      }
    }

    for (int i = j; i < n; i++) {
      nums[i] = 0;
    }
  }
};

int main() {
  Solution obj;
  vector<int> nums = {0, 1, 0, 3, 12};
  obj.moveZeroes(nums);

  for (auto i : nums) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
