#include <bits/stdc++.h>
using namespace std;

// @leet start
class Solution {
public:
  void tnp_removeDuplicates(string &nums, vector<bool> &freq, int length,
                            string &result, int idx) {
    if (idx == length) {
      cout << result;
      return;
    }

    if (freq[nums[idx] - 'a'] == false) {
      result += nums[idx];
      freq[nums[idx] - 'a'] = true;
      tnp_removeDuplicates(nums, freq, length, result, idx + 1);
    }
  }
};
// @leet end

int main() {
  Solution obj;
  string nums = "racecar";
  vector<bool> freq(26, false);
  int length = nums.length();
  obj.tnp_removeDuplicates(nums, freq, length, nums, 0);
  //
  // cout << res;

  return 0;
}
