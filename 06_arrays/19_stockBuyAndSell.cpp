#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int stockBuyAndSell(vector<int> &nums) {
    int n = nums.size();
    if (n <= 1)
      return 0;
    //
    //   brute force O(n^2)
    //   long long maxProfit = LLONG_MIN;
    //   long long profit = 0;
    //
    //   for (int i = 0; i < n - 1; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //       if (nums[j] > nums[i]) {
    //         profit = nums[j] - nums[i];
    //       }
    //
    //       maxProfit = max(maxProfit, profit);
    //     }
    //   }
    //
    //   return maxProfit;
    //
    //   optimal O(n)
    //
    long long minPrice = LLONG_MAX;
    long long maxProfit = 0;

    for (int price : nums) {
      if (price < minPrice) {
        minPrice = price;
      } else {
        maxProfit = max(maxProfit, price - minPrice);
      }
    }

    return maxProfit;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  int res = obj.stockBuyAndSell(nums);

  cout << res;

  return 0;
}
