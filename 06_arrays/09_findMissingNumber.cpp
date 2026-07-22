#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMissingNumber(vector<int>& nums) {
    // using maths
    // int n = nums.size() + 1;
    // long long expSum = ((n + 1) *1LL* n) / 2;
    // int currSum = 0;
    //
    // for (int i = 0; i < n - 1; i++) {
    //   currSum+= nums[i];
    // }
    //
    // return expSum - currSum;
    //
    // using xor avoids possible memory overflows, since it operates bit by bit
    
    int n = nums.size() + 1;
    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < n - 1; i++) {
      xor2 ^= nums[i];
      xor1 ^= (i + 1);
    }

    xor1 ^= n;
    return xor1 ^ xor2;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {8, 2, 4, 5, 3, 7, 1};
  int res = obj.findMissingNumber(nums);

  cout << res;

  return 0;
}
