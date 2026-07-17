#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxFrequency(vector<int>& nums, int k) {
    int maxFreq = 0;

    sort(nums.begin(), nums.end());

    // use a sliding window with two pointers

    
    long long windowSum = 0;
    int L = 0;

    for (int R = 0; R < nums.size(); R++) {
      windowSum += nums[R];

      while ((static_cast<long long>(R - L + 1) * nums[R] - windowSum) > k) {
        windowSum -= nums[L];
        L++;
      }

      maxFreq = max(maxFreq, R - L + 1);
    }

    return maxFreq;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 4, 8, 13};
  int k = 5;
  cout << obj.maxFrequency(nums, k);

  return 0;
}
