#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void rotateArrayByOne(vector<int>& nums) {
    int n = nums.size();
    // edge case
    if (n <= 1) return;
    int temp = nums[0];
     
    for (int i = 1; i < n; i++) {
      nums[i - 1] = nums[i];
    }
     
    nums[n - 1] = temp;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 2, 3, 4, 5};
  obj.rotateArrayByOne(nums);

  for (auto i : nums) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
