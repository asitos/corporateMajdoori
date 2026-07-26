#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
     
    int maxi = INT_MIN;
    int prod = 1;
     
    for (int i = 0; i < n; i++) {
      prod *= nums[i];
      maxi = max(prod, maxi);
      if (prod == 0) prod = 1;
    }

    for (int i = n - 1; i >= 0; i--) {
      prod *= nums[i];
      maxi = max(prod, maxi);
      if (prod == 0) prod = 1;
    }

    return maxi;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {2, 3, -2, 4};
  int res = obj.maxProduct(nums);

  cout << res;

  return 0;
}
