#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high) {
      if (nums[left] <= nums[right]) {
        temp.push_back((nums[left++]));
      } else {
        temp.push_back((nums[right++]));
      }
    }

    while (left <= mid) {
      temp.push_back(nums[left++]);
    }

    while (right <= high) {
      temp.push_back(nums[right++]);
    }

    for (int i = low; i <= high; i++) {
      nums[i] = temp[i - low];
    }
  }

public:
  void mergeSort(vector<int>& nums, int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;

    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);

    merge(nums, low, mid, high);
  }
};

int main() {
  Solution obj;
  vector<int> nums = {5, 4, 3, 2, 1};
  obj.mergeSort(nums, 0, nums.size() - 1);

  for (auto i : nums) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
