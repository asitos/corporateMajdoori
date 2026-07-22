#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int linearSearch(vector<int>& nums, int num) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      if (nums[i] == num) {
        return i;
      }
    }
     
    return -1;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {5, 4, 3, 2, 1};
  int num = 2;

  cout << obj.linearSearch(nums, num);

  return 0;
}
