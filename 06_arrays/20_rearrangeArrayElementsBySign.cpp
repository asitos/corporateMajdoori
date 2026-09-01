#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> rearrangeArrayElementsBySign(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return {};

    // brute force O(n + n/2) = O(n)
    //
    // vector<int> pos;
    // vector<int> neg;
    //
    // for (int i = 0; i < n; i++) {
    //   if (nums[i] >= 0) {
    //     pos.push_back(nums[i]);
    //   } else {
    //     neg.push_back(nums[i]);
    //   }
    // }
    //
    // for (int i = 0; i < n / 2; i++) {
    //   nums[2 * i] = pos[i];
    //   nums[2 * i + 1] = neg[i];
    // }
    //
    // return nums;
    //

    // optimal O(n) time with O(n) space for res array
    //
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
  vector<int> nums = {1, 2, -4, -5};
  vector<int> res = obj.rearrangeArrayElementsBySign(nums);

  for (auto i : res) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
