#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void sortColors(vector<int>& nums) {
    int n = nums.size();

    // edge case
    if (n <= 1) return;

    int lo = 0, mid = 0, hi = n - 1;

    while (mid <= hi) {
      if (nums[mid] == 0) {
        swap(nums[lo], nums[mid]);
        lo++;
        mid++;
      } else if (nums[mid] == 1) {
        mid++;
      } else {
        swap(nums[mid], nums[hi]);
        hi--;
      }
    }
  }
};

int main() {
  Solution obj;
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  obj.sortColors(nums);

  for (auto i : nums) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
