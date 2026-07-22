#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    // edge case
    int n = nums.size();
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
  vector<int> nums = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
  obj.moveZeroes(nums);

  for (auto i : nums) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
