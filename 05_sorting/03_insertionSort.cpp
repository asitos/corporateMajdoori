#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> insertionSort(vector<int>& nums) {
    int n = nums.size();

    for (int i = 1; i < n; i++) {
      int key = nums[i];
      int j = i - 1;

      while (j >= 0 && nums[j] > key) {
        nums[j + 1] = nums[j];
        j--;
      }

      nums[j + 1] = key;

    }
     
    return nums;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {5, 4, 3, 2, 1};
  vector<int> res = obj.insertionSort(nums);

  for (auto i : res) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
