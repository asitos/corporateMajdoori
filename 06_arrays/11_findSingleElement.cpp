#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findSingleElement(vector<int>& nums) {
    int n = nums.size();
    int xorr = 0;

    for (int i = 0; i < n; i++) {
      xorr = xorr ^ nums[i];
    } 
    
    return xorr;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {4, 2, 1, 2, 1};
  int res = obj.findSingleElement(nums);

  cout << res;

  return 0;
}
