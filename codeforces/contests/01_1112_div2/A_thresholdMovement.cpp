#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool thresholdMovement(vector<int>& nums, int n) {
     // edge case
    if (n % 2 != 0) return false;

    int min_even = INT_MAX;
    int max_odd = INT_MIN;

    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        min_even = min(min_even, nums[i]);
      } else {
        max_odd = max(max_odd, nums[i]);
      }
    }
     
    return (min_even - max_odd > 1);
  }
};

int main() {
  Solution obj;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> balls(n);

    for (int i = 0; i < n; i++) {
      cin >> balls[i];
    }

    if (obj.thresholdMovement(balls, n)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
