#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> selectionSort(vector<int>& nums) {

    for (int i = 0; i < nums.size() - 1; i++) {
      int min = i;
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[j] <= nums[min]) {
          min = j;
        }
      }

      int temp = nums[min];
      nums[min] = nums[i];
      nums[i] = temp;
    }
     
    return nums;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {5, 4, 3, 2, 1};
  vector<int> res = obj.selectionSort(nums);

  for (auto i : res) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
