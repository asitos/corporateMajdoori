#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> bubbleSort(vector<int>& nums) {
    for (int i = nums.size() - 1; i >= 0; i--) {
      int didSwap = 0;  // check for array swap
      for (int j = 0; j < i; j++) {
        if (nums[j] > nums[j + 1]) {
          swap(nums[j], nums[j + 1]);
          didSwap = 1;
        }
      }

      // break the loop with array is sorted, since no swap will occur
      if (didSwap == 0) {
        break;
      }
    }
    
    return nums;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {5, 4, 3, 2, 1};
  vector<int> res = obj.bubbleSort(nums);

  for (auto i : res) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
