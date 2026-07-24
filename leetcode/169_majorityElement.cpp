#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return nums[0];

    int cnt = 0, elem;
    for (int i = 0; i < n; i++) {
      if (cnt == 0) {
        cnt = 1;
        elem = nums[i];
      } else if (elem == nums[i]) {
        cnt++;
      } else {
        cnt--;
      }
    }

    int verifyCnt = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == elem) verifyCnt++;
    }

    if (verifyCnt > n / 2) return elem;
     
    return -1;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
  int res = obj.majorityElement(nums);

  cout << res;

  return 0;
}
