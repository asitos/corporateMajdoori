#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int xorr = 0;
     
    for (int i = 0; i < nums.size(); i++) {
      xorr ^= nums[i];
    }
     
    return xorr;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {4, 1, 2, 1, 2};
  int res = obj.singleNumber(nums);

  cout << res;

  return 0;
}
