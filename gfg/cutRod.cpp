#include <bits/stdc++.h>
using namespace std;

// @leet start
class Solution {
public:
  int cutRod(vector<int> &price) {
    int n = price.size();
    return solve(price, n);
  }

  int solve(vector<int> &price, int length) {
    // base case
    if (length == 0)
      return 0;

    int maxVal = INT_MIN;

    for (int i = 1; i <= length; i++) {
      maxVal = max(maxVal, price[i - 1] + solve(price, length - 1));
    }

    return maxVal;
  }
};
// @leet end

int main() {
  Solution obj;
  vector<int> nums = {5, 4, 3, 2, 1};
  int res = obj.cutRod(nums);

  cout << res;

  return 0;
}
