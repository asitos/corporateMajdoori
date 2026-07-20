#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {
      if (nums[j] <= pivot) {
        i++;
        swap(nums[i], nums[j]);
      }
    }

    swap(nums[i + 1], nums[high]);

    return i + 1;
  }

public:
  void quickSort(vector<int>& nums, int low, int high) {
    if (low < high) {
      int pivotIndex = partition(nums, low, high);

      quickSort(nums, low, pivotIndex - 1);

      quickSort(nums, pivotIndex + 1, high);
    }
  }
};

int main() {
  Solution obj;
  vector<int> nums = {5, 4, 3, 2, 1};

  obj.quickSort(nums, 0, nums.size() - 1);
  for (auto i : nums) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
