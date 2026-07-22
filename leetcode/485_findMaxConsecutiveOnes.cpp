#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxOnes = 0;
    int currentStreak = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1) {
        currentStreak++;
        maxOnes = max(maxOnes, currentStreak);
      } else {
        currentStreak = 0;
      }
    }
    
    return maxOnes;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 1, 0, 1, 1, 1};
  int res = obj.findMaxConsecutiveOnes(nums);

  cout << res;

  return 0;
}
