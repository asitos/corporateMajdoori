#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    // edge case
    if (n < 1) return 0;

    int i = 0;
    for (int j = 1; j < n; j++) {
      if (nums[i] != nums[j]) {
        i++;
        nums[i] = nums[j];
      }
    }
     
    return i + 1;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

  int k = obj.removeDuplicates(nums);

  cout << k << "\n";
  for (auto i : nums) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
