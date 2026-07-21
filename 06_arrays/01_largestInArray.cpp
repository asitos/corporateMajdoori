#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int largestInArray(vector<int>& nums) {
    // optimal O(n)
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] >= res) {
        res = nums[i];
      }
    }

    //brute force O(nlogn)
    // sort(nums.begin(), nums.end());
    // return nums[nums.size() - 1];
     
    return res;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {8, 10, 5, 7, 9};
  int res = obj.largestInArray(nums);

  cout << res;

  return 0;
}
