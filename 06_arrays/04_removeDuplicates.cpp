#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> removeDuplicates(vector<int>& nums) {
    // edge case
    if (nums.size() <= 1) return nums;
     
    int i = 0, j = 1;
    for (int j = 1; j < nums.size(); j++) {
      if (nums[j] != nums[i]) {
        i++;
        nums[i] = nums[j];
      }
    }
    
    return nums;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 1, 2, 2, 2, 3, 3};
  vector<int> res = obj.removeDuplicates(nums);

  for (auto i : res) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
