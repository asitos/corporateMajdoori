#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> nextPermutation(vector<int> &nums) {
    vector<int> res;

    return res;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {5, 4, 3, 2, 1};
  vector<int> res = obj.nextPermutation(nums);

  for (auto i : res) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
