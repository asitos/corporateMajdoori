#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> rearrangeArray(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return {};

    vector<int> res(n, 0);
    int pos = 0, neg = 1;

    for (int i = 0; i < n; i++) {
      if (nums[i] >= 0) {
        res[pos] = nums[i];
        pos += 2;
      } else {
        res[neg] = nums[i];
        neg += 2;
      }
    }

    return res;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {3, 1, -2, -5, 2, -4};
  vector<int> res = obj.rearrangeArray(nums);

  for (auto i : res) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
