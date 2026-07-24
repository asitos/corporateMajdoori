#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void sortZeroOneTwo(vector<int>& nums) {
    // dutch national flag algorithm
    int n = nums.size();
    // edge case
    if (n <= 1) return;
    
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
      if (nums[mid] == 0) {
        swap(nums[mid], nums[low]);
        mid++;
        low++;
      } else if (nums[mid] == 1) {
        mid++;
      } else {
        swap (nums[mid], nums[high]);
        high--;
      }
    }
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 0, 2, 1, 0};
  obj.sortZeroOneTwo(nums);

  for (auto i : nums) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
