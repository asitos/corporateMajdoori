#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int n = nums.size();

    if (n <= 1) return nums[0];

    // hashmap approach
    // unordered_map<int, int> mp;
    // for (int i = 0; i < n; i++) {
    //   // count freq of each elem
    //   mp[nums[i]]++;
    // }
    //
    //
    // for (auto& pair : mp) {
    //   if (pair.second > n / 2) {
    //     return pair.first;
    //   }
    // }
    //
    // return -1;
    //
    // optimal approach

    int cnt = 0, elem; 
    for (int i = 0; i < n; i++) {
      if (cnt == 0) {
        cnt = 1;
        elem = nums[i];
      } else if (elem == nums[i]) {
        cnt++;
      } else {
        cnt--;
      }
    }

    int verifyCnt = 0;
    for (int i =0; i < n; i++) {
      if (nums[i] == elem) verifyCnt++;
    }

    if (verifyCnt > n / 2) return elem;
    
    return -1;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {7, 0, 0, 1, 7, 7, 2, 7, 7};
  int res = obj.majorityElement(nums);

  cout << res;

  return 0;
}
