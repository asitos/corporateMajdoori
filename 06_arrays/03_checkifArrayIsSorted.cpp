#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool checkifArrayIsSorted(vector<int>& nums) {

    if (nums.size() <= 1) return true;
     
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i + 1] < nums[i]) {
        return false;
      }
    }
     
    return true;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 2, 3, 4, 5};

  cout << obj.checkifArrayIsSorted(nums);

  return 0;
}
