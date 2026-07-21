#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool check(vector<int>& nums) {
    int n = nums.size();
    int drops = 0;

    if (n <= 1) return true;
     
    for (int i = 0; i < n; i++) {
      if (nums[i] > nums[(i + 1) % n]) {
        drops++; 
      }
    }
     
    return (drops <= 1);
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 2, 3, 4, 5};

  cout << obj.check(nums);

  return 0;
}
