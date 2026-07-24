#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
      int j = target - nums[i];

      if (mp.find(j) != mp.end()) {
        return {mp[j], i};
      }

      mp[nums[i]] = i;
    }
    
    return {-1, -1};
  }
};

int main() {
  Solution obj;
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> res = obj.twoSum(nums, target);

  for (auto i : res) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
